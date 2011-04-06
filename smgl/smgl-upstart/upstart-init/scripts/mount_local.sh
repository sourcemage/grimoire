#!/bin/bash
# mount_all
#
# mount local filesystems
# based on the init.d init scripts

  [ -e /etc/sysconfig/init ] && . /etc/sysconfig/init
  [ -e /etc/sysconfig/mountall ] && . /etc/sysconfig/mountall

#  if [ -x /usr/sbin/cryptsetup ] && [ -f /etc/crypttab ]; then
#    echo "Attempting to open luks encrypted partitions"
#    grep -v '^#' /etc/crypttab |
#    grep -v '^$'               |
#    while read line
#    do
#      if [ -z "$line" ]; then
#        echo "empty crypttab, skipping"
#      else
#        parts=( $line )
#        echo "Opening ${parts[0]} as ${parts[1]}"
#        if cryptsetup isLuks ${parts[0]}; then
#          if [[ -b /dev/mapper/${parts[1]} ]]; then
#            builtin echo "Device already exists maybe its open already"
#          else
#            cryptsetup luksOpen ${parts[0]} ${parts[1]} < /dev/console > /dev/console 2>&1
#          fi
#        else
#          builtin echo "Error device ${parts[0]} isn't a luks partition"
#        fi
#      fi
#    done
#  fi

#  [ -e /fastboot     ]  &&  return
  [ -e /forcefsck    ]  &&  FORCE="-f"
  [ "$NOSOFTFIX" != yes ]  &&  FIX="-a"
  [ "$FSCKFIX" = yes ]  &&  FIX="-y"
  [ -z  "$FIX"       ]  &&  FIX="-n" # need at least -n, -y, or -a for non-tty fsck
  [ "$FORCE"   = yes ]  &&  FORCE="-f"

  echo "Checking file systems..."
  fsck -T -C -A -R $FIX $FORCE
  if [ $? -gt 1 ];  then
    $WARNING
    echo  "fsck failed."
    echo  "Please repair your file system"
    echo  "manually by running /sbin/fsck"
    echo  "without the -a option"
    $NORMAL
 #   /sbin/sulogin
 #   /sbin/reboot  -f
    echo "$WARNING WTF! repair your fs! $NORMAL"
 fi

  [ -e /fastboot ] && rm -f /fastboot
  [ -e /forcefsck ] && rm -f /forcefsck

  if [ -x /sbin/swapon ]; then
    echo "Activating swap... "
    swapon -a
  fi

  echo "Mounting local filesystems..."
# Fixed so as to not mount networked filesystems yet (no networking)
# mountnetwork.sh will take care of this.
  mount -a  -t  nocifs,noncpfs,nonfs,nosmbfs,notmpfs,no9p
# mount tmpfs mounts after physical partitions they might mount to (bug 3597)
  mount -a  -t tmpfs

#  # bug 7311 - if proc was mounted, list it in mtab; awk is /usr friendly
#  if awk 'BEGIN{proc=1} /\/proc/{proc=0} END{exit proc}' /proc/mounts; then
#    builtin echo 'none /proc proc rw 0 0' >> /etc/mtab
#  fi

#As per FHS sm bug #10509
#FIXME: doing this here kills upstart... fix this bug again later...
#  echo "Cleaning out /var/run..."
#  [ -d /var/run ] && rm -rf /var/run/*

#  if [ "$CLEAN_TMP" == "yes" ] ; then
#    echo "Cleaning out /tmp..."
#    [ -d /tmp ] && shopt -s dotglob && rm -rf /tmp/* && shopt -u dotglob
#  fi

  echo "Creating /var/run/utmp..."
  [ -d /var/run ] && touch /var/run/utmp

  echo "Writing dmesg log to /var/log/dmesg..."
  [ -d /var/log ] && dmesg  >  /var/log/dmesg

  echo "Making /tmp/.ICE-unix temporary directory..."
  [ -d /tmp     ] && mkdir -p /tmp/.ICE-unix && chmod 1777 /tmp/.ICE-unix

  initctl emit --no-wait mounted-localfs
  echo "done mounting other filesystems"
