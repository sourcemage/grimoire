#!/bin/bash

PROGRAM=/sbin/hwclock
RUNLEVEL=S
NEEDS="+local_fs"
RECOMMENDED=yes

. /etc/init.d/smgl_init
. /etc/sysconfig/hwclock

                      tz_arg="--localtime"
[ "$UTC" = "yes" ] && tz_arg="--utc"

test -x /sbin/hwclock || exit 5

start()
{
  echo "Setting System Time using the Hardware Clock..."
  $PROGRAM --hctosys $tz_arg
  evaluate_retval
}

stop()
{
  echo "Setting the Hardware Clock to the current System Time..."
  $PROGRAM --systohc $tz_arg
  evaluate_retval
}

adjust()
{
  echo "Adjusting the Hardware Clock to account for drift..."
  $PROGRAM --adjust
  evaluate_retval
}

show()
{
  echo "Show Hardware Clock time."
  $PROGRAM --show
}
