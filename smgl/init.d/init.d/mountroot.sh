#!/bin/bash
# vim:set ts=2 sw=2 et:

PROGRAM=/bin/false
RUNLEVEL=S
PROVIDES=root_fs
ESSENTIAL=yes

. /etc/init.d/smgl_init
. /etc/sysconfig/init

checkrootfs()
{
  [ -e /fastboot     ]  &&  return
  [ -e /forcefsck    ]  &&  FORCE="-f"
  [ "$NOSOFTFIX" != yes ]  &&  FIX="-a"
  [ "$FSCKFIX" = yes ]  &&  FIX="-y"
  [ -z  "$FIX"       ]  &&  FIX="-n" # need at least -n, -y, or -a for non-tty fsck
  [ "$FORCE"   = yes ]  &&  FORCE="-f"

  echo "Checking root file system..."
  /sbin/fsck -T -C $FIX $FORCE /
  evaluate_retval

  if [ $? -gt 1 ];  then
    $WARNING
    echo  "fsck failed."
    echo  "Please repair your file system"
    echo  "manually by running /sbin/fsck"
    echo  "without the -a option"
    $NORMAL
    /sbin/sulogin
    /sbin/reboot  -f
  fi
}

scanlvm()
{
  # find devices that were set up in initramfs/rd
  if optional_executable /sbin/dmsetup
  then 
    echo "(re)Creating device mapper nodes..."
    # won't check retval because kernel just may lack device mapper
    /sbin/dmsetup mknodes
  fi

  if optional_executable /sbin/vgscan && optional_executable /sbin/vgchange ; then
    echo "Scanning for and initializing all available LVM volume groups..."
    /sbin/vgscan       --ignorelockingfailure  --mknodes  &&
    /sbin/vgchange -ay --ignorelockingfailure
  fi
}

start()
{
  required_executable /bin/mount
  required_executable /sbin/fsck

  #
  # Prefer the newer mdadm to raidtools
  #
  if   [ -f /etc/mdadm.conf ] ; then
    mdadm  --assemble  --scan  --run
    mdadm  --follow    --scan  --delay=120  --daemonise
  elif [ -f /etc/raidtab    ] ; then
    raidstart  --all
  fi

  scanlvm
  evaluate_retval

  echo "Mounting root file system read only..."
  mount   -n  -o  remount,ro  /
  evaluate_retval || exit 1

  checkrootfs

  echo "Mounting root file system read/write..."
  {
    mount    -n -o remount,rw / &&
    if ! [[ -h /etc/mtab ]]; then
      builtin echo > /etc/mtab
    fi &&
    mount    -f -o remount,rw /
  } || exit 1

  evaluate_retval || exit 1

  exit 0
}


# Simpleinit handles umounting and stuff.
stop()
{
  exit 0
}

restart()       { exit 3; }
reload()        { exit 3; }
force_reload()  { exit 3; }
status()        { exit 3; }

usage()
{
  echo "Usage: $0 {start|stop}"
  echo "Warning: Do not run this script manually!"
}
