#!/bin/bash

PROGRAM=/bin/loadkeys
RUNLEVEL=S
NEEDS="+local_fs"
RECOMMENDED=yes

. /etc/init.d/smgl_init
. /etc/sysconfig/keymap
. /etc/sysconfig/devices

start()
{
  required_executable /bin/loadkeys

  /bin/loadkeys $KEYMAP
  evaluate_retval

  if [[ "$DEVICES" == "devfs" ]]
  then
    DEV_TTY="vc/"
  else
    DEV_TTY="tty"
  fi

  if [ -e "/usr/bin/consolechars" ]
  then
    required_executable /usr/bin/consolechars
    CONSOLE_TOOLS="console-tools"
  elif [ -e "/usr/bin/setfont" ]
  then
    required_executable /usr/bin/setfont
    CONSOLE_TOOLS="kbd"
  fi
  if [[ "$UNICODE_START" ]]
  then
    required_executable /usr/bin/unicode_start
    kbd_mode -u
    dumpkeys | loadkeys --unicode
  fi

  if [[ "$CONSOLE_TOOLS" == "console-tools" ]]
  then
    if [ "$ENABLE_EURO" = "yes" ]
    then
      /bin/loadkeys euro.inc
      evaluate_retval
    fi

    if [[ "$TTY_NUMS" ]] && [[ "$CONSOLECHARS_ARGS" ]]
    then
      for n in $TTY_NUMS
      do
        echo "Setting console settings for $DEV_TTY$n..."
        if [[ "$UNICODE_START" ]]
        then
          /bin/echo -ne "\033%G" > /dev/$DEV_TTY$n
          /usr/bin/consolechars $CONSOLECHARS_ARGS --tty=/dev/$DEV_TTY$n
          evaluate_retval
        else
          /usr/bin/consolechars $CONSOLECHARS_ARGS --tty=/dev/$DEV_TTY$n
          evaluate_retval
        fi
      done
    fi
  fi

  if [[ "$CONSOLE_TOOLS" == "kbd" ]]
  then
    if [[ "$TTY_NUMS" ]] && [[ "$SETFONT_ARGS" ]]
    then
      for n in $TTY_NUMS 
      do
        echo "Setting console settings for $DEV_TTY$n..."
        if [[ "$UNICODE_START" ]]
        then
          /bin/echo -ne "\033%G" > /dev/$DEV_TTY$n
          /usr/bin/setfont $SETFONT_ARGS -C /dev/$DEV_TTY$n
          evaluate_retval
        else
          /usr/bin/setfont $SETFONT_ARGS -C /dev/$DEV_TTY$n
          evaluate_retval
        fi          
      done
    fi
  fi
}

stop()
{
  echo  "Cannot stop keymap"
}
