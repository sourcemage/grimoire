#!/bin/bash
# vim:set ts=2 sw=2 et:

PROGRAM=/bin/false
RUNLEVEL=S
NEEDS="+root_fs"
WANTS="+modules +crypt_fs"
PROVIDES=local_fs
ESSENTIAL=yes

. /etc/init.d/smgl_init
. /etc/sysconfig/init
. /etc/sysconfig/mountall

function recursive_rm() {
  for file in "$@" ; do
    if [ -h $file ] ; then
      unlink $file
    elif [ -d $file ] ; then
      recursive_rm "$file"/*
    else
      rm -f "$file"
    fi
  done
}

checkfs()
{
  if [ -e /fastboot ]; then
    rm -f /fastboot;
    return;
  fi
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

  rm -f /forcefsck
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

start_cryptfs()
{
  if optional_executable /usr/sbin/cryptsetup && [ -f /etc/crypttab ]
  then
    echo "Attempting to open luks encrypted partitions"
    grep -v '^#' /etc/crypttab |
    grep -v '^$'               |
    while read line
    do
      parts=( $line )
      echo "Opening ${parts[0]} as ${parts[1]}"
      if cryptsetup isLuks ${parts[0]}
      then
        if [[ -b /dev/mapper/${parts[1]} ]]
        then
          builtin echo "Device already exists maybe its open already"
        else
          cryptsetup luksOpen ${parts[0]} ${parts[1]} < /dev/console > /dev/console 2>&1
        fi
      else
        builtin echo "Error device ${parts[0]} isn't a luks partition"
        return 1
      fi
    done
  fi
}

start()
{
  required_executable /bin/mount
  required_executable /sbin/fsck

  scanlvm
  evaluate_retval

  start_cryptfs
  evaluate_retval

  checkfs

  if optional_executable /sbin/swapon ; then
    echo -n "Activating swap... "
    swapon -a 2> /dev/null
    evaluate_retval
  fi

  echo "Mounting local filesystems..."
# Fixed so as to not mount networked filesystems yet (no networking)
# mountnetwork.sh will take care of this.
  mount    -a  -t  nocifs,noncpfs,nonfs,nosmbfs,notmpfs,no9p
# mount tmpfs mounts after physical partitions they might mount to (bug 3597)
  mount    -a  -t tmpfs
  evaluate_retval

  # bug 7311 - if proc was mounted, list it in mtab; awk is /usr friendly
  if awk 'BEGIN{proc=1} /\/proc/{proc=0} END{exit proc}' /proc/mounts; then
    builtin echo 'none /proc proc rw 0 0' >> /etc/mtab
  fi

#As per FHS sm bug #10509
  echo "Cleaning out /var/run..."
  [ -d /var/run ] && recursive_rm /var/run/*
  evaluate_retval

  if [ "$CLEAN_TMP" == "yes" ] ; then
    echo "Cleaning out /tmp..."
    [ -d /tmp ] && find /tmp -mindepth 1 -delete
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
