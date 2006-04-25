#!/bin/sh
# vim:set ts=2 sw=2 et:

PROGRAM=/bin/false
RUNLEVEL=S
NEEDS="+root_fs"
WANTS="+modules"
PROVIDES=local_fs
ESSENTIAL=yes

. /etc/init.d/smgl_init
. /etc/sysconfig/init
. /etc/sysconfig/mountall

function recursive_rm() {
  for file in "$@" ; do
    if [ -d $file ] ; then
      recursive_rm "$file"/*
    else
      rm -f "$file"
    fi
  done
}

checkfs()
{
  [ -e /fastboot     ]  &&  return
  [ -e /forcefsck    ]  &&  FORCE="-f"
  [ "$NOSOFTFIX" != yes ]  &&  FIX="-a"
  [ "$FSCKFIX" = yes ]  &&  FIX="-y"
  [ -z  "$FIX"       ]  &&  FIX="-n" # need at least -n, -y, or -a for non-tty fsck
  [ "$FORCE"   = yes ]  &&  FORCE="-f"

  echo "Checking file systems..."
  /sbin/fsck -T -C -A -R $FIX $FORCE
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

  echo "Mounting proc file system..."
  mount -a -t /proc
  evaluate_retval

  checkfs

  if optional_executable /sbin/swapon ; then
    echo -n "Activating swap... "
    swapon -a 2> /dev/null
    evaluate_retval
  fi

  echo "Mounting local filesystems..."
# Fixed so as to not mount networked filesystems yet (no networking)
# mountnfs.sh will take care of this.
  mount    -a  -t  nosmbfs,nonfs,noncpfs,notmpfs
# mount tmpfs mounts after physical partitions they might mount to (bug 3597)
  mount    -a  -t tmpfs
  evaluate_retval

#As per FHS sm bug #10509
  echo "Cleaning out /var/run..."
  [ -d /var/run ] && recursive_rm /var/run/*
  evaluate_retval

  if [ "$CLEAN_TMP" == "yes" ] ; then
    echo "Cleaning out /tmp..."
    [ -d /tmp ] && rm -rf /tmp/*
    evaluate_retval
  fi

  echo "Creating /var/run/utmp..."
  [ -d /var/run ] && touch /var/run/utmp
  evaluate_retval

  echo "Writing dmesg log to /var/log/dmesg..."
  [ -d /var/log ] && dmesg  >  /var/log/dmesg
  evaluate_retval

  echo "Making /tmp/.ICE-unix temporary directory..."
  [ -d /tmp     ] && mkdir -p /tmp/.ICE-unix && chmod 1777 /tmp/.ICE-unix
  evaluate_retval

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
