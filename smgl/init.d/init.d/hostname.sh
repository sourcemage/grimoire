#!/bin/bash

PROGRAM=/bin/hostname
RUNLEVEL=S
RECOMMENDED=yes

. /etc/init.d/smgl_init

start()
{
  required_executable /bin/hostname
  required_executable /sbin/ifconfig

  echo "Setting hostname..."
  # not -F /etc/hostname since coreutils hostname doesn't like it.
  /bin/hostname "`cat /etc/hostname`"
  evaluate_retval

  if [ -e /etc/defaultdomain ]; then
    echo "Setting domain name..."
    /bin/domainname "`cat /etc/defaultdomain`"
    evaluate_retval
  fi

  echo "Setting up local network interface..."
  ifconfig lo 127.0.0.1 broadcast 127.255.255.255 netmask 255.0.0.0
  evaluate_retval
}

stop()
{
  echo  "Cannot stop hostname"
}
