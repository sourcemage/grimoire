#!/bin/bash

PROGRAM=/bin/loadkeys
RUNLEVEL=S
NEEDS="+local_fs"
RECOMMENDED=yes

. /etc/init.d/smgl_init
. /etc/sysconfig/keymap

start()
{
  required_executable /bin/loadkeys

  /bin/loadkeys $KEYMAP
  evaluate_retval

  if [ "$ENABLE_EURO" = "yes" ] ; then
    /bin/loadkeys euro.inc
    evaluate_retval
  fi

  if [ "$CONSOLECHARS_ARGS" ] ; then
    required_executable /usr/bin/consolechars

    echo "Setting console settings..."
    /usr/bin/consolechars $CONSOLECHARS_ARGS
    evaluate_retval
  fi
}

stop()
{
  echo  "Cannot stop keymap"
}
