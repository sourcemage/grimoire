#!/bin/bash

PROGRAM=/bin/loadkeys
RUNLEVEL=S
NEEDS="+local_fs"
RECOMMENDED=yes

. /etc/init.d/smgl_init
. /etc/sysconfig/keymap
. /etc/sysconfig/devices

dropfile=/var/tmp/keymap.drop

start()
{
  [[ "$TTY_NUMS" ]] && [[ "$CONSOLECHARS_ARGS" ]] &&
    required_executable /usr/bin/consolechars
  [[ "$KEYMAP$INCLUDEMAPS" ]] &&
    required_executable /bin/loadkeys

  if [[ "$KEYMAP" ]]; then
    echo "$(/bin/loadkeys $KEYMAP 2>&1)"
    evaluate_retval
  fi

  for a in $INCLUDEMAPS; do
    [[ $(find /usr/share/keymaps/ -type f -name "$a.inc*" 2>/dev/null) ]] &&
    [[ ! $(find /usr/share/keymaps/ -type f -name "$a.kmap*" 2>/dev/null) ]] &&
      a="$a.inc"
    echo "$(/bin/loadkeys $a 2>&1)"
    evaluate_retval
  done

  [[ "$DEVICES" == "devfs" ]] && DEV_TTY="vc/" || DEV_TTY="tty"

  if [[ "$UNICODE_START" ]]; then
    required_executable /usr/bin/unicode_start
    /usr/bin/kbd_mode -u
  fi

  if [[ "$TTY_NUMS" == '*' ]]; then
    TTY_NUMS=
    for a in $(grep ^tty.*: /etc/inittab); do
      TTY_NUMS="$TTY_NUMS $(expr "$a" : 'tty\([0-9]*\):.*')"
    done
  fi

  for n in $TTY_NUMS; do
    echo "Loading settings for $DEV_TTY$n..."
    if [[ "$CONSOLECHARS_ARGS" ]]; then
      /usr/bin/consolechars $CONSOLECHARS_ARGS --tty=/dev/$DEV_TTY$n
      evaluate_retval
    fi
    [[ "$UNICODE_START" ]] && /bin/echo -ne "\033%G" > /dev/$DEV_TTY$n
  done

  [[ -f $dropfile ]] && rm $dropfile
  STATUS_VARS="KEYMAP INCLUDEMAPS CONSOLECHARS_ARGS TTY_NUMS UNICODE_START DEV_TTY"
  for a in $STATUS_VARS; do
    /bin/echo "$a=\"${!a}\"" >> $dropfile
  done
}

stop()
{
  [[ "$TTY_NUMS" ]] && [[ "$CONSOLECHARS_ARGS" ]] &&
    required_executable /usr/bin/consolechars

  [[ -f $dropfile ]] && . $dropfile && rm $dropfile

  [[ "$KEYMAP$INCLUDEMAPS" ]] &&
    required_executable /bin/loadkeys &&
    echo "$(/bin/loadkeys defkeymap 2>&1)"

  [[ "$UNICODE_START" ]] &&
    required_executable /usr/bin/unicode_stop &&
    /usr/bin/kbd_mode -a

  for n in $TTY_NUMS; do
    echo "Unloading settings for $DEV_TTY$n..."
    [[ "$UNICODE_START" ]] && /bin/echo -ne '\033%@' > /dev/$DEV_TTY$n
    if [[ "$CONSOLECHARS_ARGS" ]]; then
      /usr/bin/consolechars -d --tty=/dev/$DEV_TTY$n
      evaluate_retval
    fi
  done
}

status()
{
  if [[ ! -f $dropfile ]]; then
    echo "No status info available."
    return 1
  fi

  . $dropfile

  echo "KEYMAP=\"$KEYMAP\""
  echo "INCLUDEMAPS=\"$INCLUDEMAPS\""
  echo "CONSOLECHARS_ARGS=\"$CONSOLECHARS_ARGS\""
  echo "TTY_NUMS=\"$TTY_NUMS\""
  echo "UNICODE_START=\"$UNICODE_START\""
}
