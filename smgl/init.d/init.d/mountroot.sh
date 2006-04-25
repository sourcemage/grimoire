#!/bin/sh
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

  rm -f /fastboot /forcefsck
}

start()
{
  required_executable /bin/mount
  required_executable /sbin/fsck

  #
  # Prefer the newer mdadm to raidtools
  #
  if   [ -f /etc/mdadm.conf ] ; then
    mdadm  --assemble  --scan
    mdadm  --follow    --scan  --delay=120  --daemonise  >  /var/run/mdadm.pid
  elif [ -f /etc/raidtab    ] ; then
    raidstart  --all
  fi

  echo "Mounting root file system read only..."
  mount   -n  -o  remount,ro  /
  evaluate_retval || exit 1

  checkrootfs

  echo "Mounting root file system read/write..."
  {
    mount    -n -o remount,rw / &&
    echo     > /etc/mtab        &&
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
