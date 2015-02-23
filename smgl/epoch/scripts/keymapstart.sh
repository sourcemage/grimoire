#!/bin/sh

. /etc/sysconfig/keymap
. /etc/sysconfig/devices

dropfile=/var/tmp/keymap.drop

  if [[ "$KEYMAP" ]]; then
    /bin/loadkeys $KEYMAP 2>&1
  fi

  for a in $INCLUDEMAPS; do
    [[ $(find /usr/share/kbd/keymaps/ -type f -name "$a.inc*" 2>/dev/null) ]] &&
    [[ ! $(find /usr/share/kbd/keymaps/ -type f -name "$a.map*" 2>/dev/null) ]] &&
      a="$a.inc"
     /bin/loadkeys $a 2>&1
  done

  [[ "$DEVICES" == "devfs" ]] && DEV_TTY="vc/" || DEV_TTY="tty"

  if [[ "$UNICODE_START" ]]; then
    /bin/kbd_mode -u
    /bin/dumpkeys | /bin/loadkeys --unicode
  fi

  if [[ "$TTY_NUMS" == '*' ]]; then
    TTY_NUMS=
    for a in $(grep ^tty.*: /etc/inittab); do
      TTY_NUMS="$TTY_NUMS $(expr "$a" : 'tty\([0-9]*\):.*')"
    done
  fi

  for n in $TTY_NUMS; do
    [[ "$UNICODE_START" ]] && /bin/echo -ne "\033%G" > /dev/$DEV_TTY$n
    if [[ "$SETFONT_ARGS" ]]; then
      /bin/setfont $SETFONT_ARGS -C /dev/$DEV_TTY$n
    fi
  done

  [[ -f $dropfile ]] && rm $dropfile
  STATUS_VARS="KEYMAP INCLUDEMAPS SETFONT_ARGS TTY_NUMS UNICODE_START DEV_TTY"
  for a in $STATUS_VARS; do
    /bin/echo "$a=\"${!a}\"" >> $dropfile
  done
