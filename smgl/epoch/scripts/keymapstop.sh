#!/bin/bash

. /etc/sysconfig/keymap
. /etc/sysconfig/devices

dropfile=/var/tmp/keymap.drop

  [[ "$TTY_NUMS" ]] && [[ "$SETFONT_ARGS" ]]

  [[ -f $dropfile ]] && . $dropfile && rm $dropfile

  [[ "$KEYMAP$INCLUDEMAPS" ]] &&
    /bin/loadkeys defkeymap 2>&1

  [[ "$UNICODE_START" ]] &&
    /bin/kbd_mode -a

  for n in $TTY_NUMS; do
    [[ "$UNICODE_START" ]] && /bin/echo -ne '\033%@' > /dev/$DEV_TTY$n
    if [[ "$SETFONT_ARGS" ]]; then
      /bin/setfont default8x16 -C /dev/$DEV_TTY$n
    fi
  done
  
