#!/bin/bash
# mount_root
#
# mount root filesystem and pseudo filesystems
# based on the init.d init scripts

  [ -e /etc/sysconfig/init ] && . /etc/sysconfig/init

  # proc and sys are needed for scanlvm
  mount -t proc proc /proc
  mount -t sysfs sysfs /sys

  echo "Mounting root file system read write..."
  mount   -n  -o  remount,rw  /

  # find devices that were set up in initramfs/rd
  if [ -x /sbin/dmsetup ];  then 
    echo "(re)Creating device mapper nodes..."
    # Make sure dmsetup doesn't halt mount_root because kernel just may
    # lack device mapper
    dmsetup mknodes
    echo "Done messing with device nodes"
  else
    echo "Not running dmsetup"
  fi

  if [ -x /sbin/vgscan ] && [ -x /sbin/vgchange ]; then
    echo "Scanning for and initializing all available LVM volume groups..."
    /sbin/vgscan       --ignorelockingfailure  --mknodes
    /sbin/vgchange -ay --ignorelockingfailure
  else
    echo "Not starting LVM"
  fi 

  if   [ -f /etc/mdadm.conf ] ; then
    echo "Running mdadm"
    mdadm  --assemble  --scan
    mdadm  --follow    --scan  --delay=120  --daemonise  >  /var/run/mdadm.pid
  elif [ -f /etc/raidtab    ] ; then
    echo "Running raidstart"
    raidstart  --all
  else
    echo "Not auto-starting RAID"
  fi

  echo "Mounting root file system read only..."
  mount   -n  -o  remount,ro  /

  echo "Checking rootfs"
  [ -e /fastboot     ]  &&  return
  [ -e /forcefsck    ]  &&  FORCE="-f"
  [ "$NOSOFTFIX" != yes ]  &&  FIX="-a"
  [ "$FSCKFIX" = yes ]  &&  FIX="-y"
  [ -z  "$FIX"       ]  &&  FIX="-n" # need at least -n, -y, or -a for non-tty fsck
  [ "$FORCE"   = yes ]  &&  FORCE="-f"

  echo "Checking root file system..."
  /sbin/fsck -T -C $FIX $FORCE /
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

  echo "Mounting root file system read/write..."
  mount    -n -o remount,rw /
  if ! [ -h /etc/mtab ]; then
    builtin echo > /etc/mtab
  fi
  mount    -f -o remount,rw /

  mount -t tmpfs lock /var/lock
# upstart uses /var/run, do not mount a tmpfs over it
#  mount -t tmpfs run /var/run
  mount -t tmpfs tmp /tmp

#  [[ -x /sbin/selinuxenabled ]] && if selinuxenabled ; then
#    [[ -d /selinux ]] || mkdir -p /selinux
#    mount -t selinuxfs selinux /selinux
#  fi

  initctl emit --no-wait mounted-rootfs || echo "failed preparing your rootfs"
  echo "done processing mout_root"
