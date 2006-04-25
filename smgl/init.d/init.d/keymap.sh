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
  if [ -n "$KEYMAP$INCLUDEMAPS" ]; then
    required_executable /bin/loadkeys
  fi

  if [ -n "$KEYMAP" ]; then
    /bin/loadkeys $KEYMAP
    evaluate_retval
  fi

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
    for a in $INCLUDEMAPS; do
      ! [[ "$a" =~ "\.gz$" ]] &&
        ! [[ "$a" =~ "\.inc$" ]] &&
        a="$a.inc"
      /bin/loadkeys $a
      evaluate_retval
    done
    if [[ "$TTY_NUMS" ]] && [[ "$CONSOLECHARS_ARGS" ]]
    then
      if [[ "$TTY_NUMS" =~ "\*" ]]; then
        unset TTY_NUMS
        for a in `grep ^tty.*: /etc/inittab`; do
          TTY_NUMS="$TTY_NUMS `expr "$a" : 'tty\([0-9]*\):.*'`"
        done
      fi
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
    for a in $INCLUDEMAPS; do
      /bin/loadkeys $a
      if [[ $? != 0 ]]; then
        ! [[ "$a" =~ "\.inc$" ]] && a="$a.inc" && /bin/loadkeys $a
      fi
      evaluate_retval
    done
    if [[ "$TTY_NUMS" ]] && [[ "$SETFONT_ARGS" ]]
    then
      if [[ "$TTY_NUMS" =~ "\*" ]]; then
        unset TTY_NUMS
        for a in `grep ^tty.*: /etc/inittab`; do
          TTY_NUMS="$TTY_NUMS `expr "$a" : 'tty\([0-9]*\):.*'`"
        done
      fi
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
