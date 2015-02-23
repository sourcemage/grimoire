#!/bin/sh

. /etc/sysconfig/devices

udev_mknodes()
{
  if [ ! -d $udev_root/fd ]; then
    ln -fs /proc/self/fd $udev_root/fd
  fi
  ln -s /dev/fd/0 $udev_root/stdin
  ln -s /dev/fd/1 $udev_root/stdout
  ln -s /dev/fd/2 $udev_root/stderr
  mkdir $udev_root/shm
  mkdir $udev_root/pts
}

start_udev()
{ (
  . /etc/udev/udev.conf
  if findmnt devtmpfs > /dev/null 2>&1; then
    true
  else
    mount -n -t ramfs none $udev_root
  fi
  # create some needed stuff
  udev_mknodes

# strip out kernel sublevel and patchlevel so we can check against them
# since we don't support 1.x linux kernels then we don't have to check that
  PATCHLEVEL=`uname -r | cut -d. -f2`
  SUBLEVEL=`uname -r | cut -d. -f3`
  tmp=`uname -r | cut -d. -f3 | sed 's/^[0-9]*//g'`
  SUBLEVEL=${SUBLEVEL/$tmp/}

  # kernel 2.6.15-rc1 and higher don't use hotplug
  if [[  $(uname -r)  =  3.*  ]] || [ $SUBLEVEL -ge 15 -a $PATCHLEVEL -ge 6 ]; then
    echo > /proc/sys/kernel/hotplug
  else
      # Now uses udevsend as the hotplug multiplexer
    sysctl -w kernel.hotplug="/sbin/udevsend" > /dev/null 2>&1
    /sbin/udevstart
  fi

  if [ -f /etc/udev/udev.missing ]; then
    cd /dev
    while read line; do
      if [ "${line:0:1}" == "#" ]; then continue; fi
      for ((i=0; i<7; i++)); do
        val[$i]=${line%%:*}
        line=${line#*:}
      done
      if [ "${val[1]}" == "d" ]; then
        mkdir ${val[0]}
      else
        mknod ${val[0]} ${val[1]} ${val[2]} ${val[3]}
      fi
      chmod ${val[4]} ${val[0]}
      chown ${val[5]}:${val[6]} ${val[0]}
    done < /etc/udev/udev.missing
    cd /
  fi
  kill -USR1 1
) }

eval "start_$DEVICES"
/sbin/udevd --daemon
/sbin/udevadm trigger
/sbin/udevadm settle --timeout=60
