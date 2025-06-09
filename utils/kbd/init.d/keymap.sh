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
  [[ "$TTY_NUMS" ]] && [[ "$SETFONT_ARGS" ]] &&
    required_executable /bin/setfont
  if [[ "$KEYMAP$INCLUDEMAPS" ]]; then
    required_executable /bin/loadkeys
    # Add .inc suffix for known files, just in case, shouldn't be needed
    INCLUDEMAPS=$(echo "$INCLUDEMAPS" | sed -E 's/\<(azerty-layout|compose|euro1|linux-keys-bare|linux-keys-extd|linux-with-alt-and-altgr|linux-with-modeshift-altgr|linux-with-two-alt-keys|qwerty-layout|qwertz-layout|apple-a1048-base|apple-a1243-fn-reverse|apple-a1243-fn|mac-azerty-layout|mac-linux-keys-bare|mac-qwerty-layout|mac-qwertz-layout)\>/&.inc/g')
    /bin/loadkeys $KEYMAP $INCLUDEMAPS 2>&1
    evaluate_retval
  fi

  [[ "$DEVICES" == "devfs" ]] && DEV_TTY="vc/" || DEV_TTY="tty"

  if [[ "$UNICODE_START" ]]; then
    required_executable /bin/unicode_start
    /bin/kbd_mode -u
    /bin/dumpkeys | /bin/loadkeys --unicode
  fi

  [[ "$TTY_NUMS" == '*' ]] &&
    TTY_NUMS=$(awk -F: '/^tty[0-9]*:/ { n=$1; sub(/^tty/, "", n); print n }' /etc/inittab)

  for n in $TTY_NUMS; do
    echo "Loading settings for $DEV_TTY$n..."
    [[ "$UNICODE_START" ]] && echo -ne "\033%G" > /dev/$DEV_TTY$n
    if [[ "$SETFONT_ARGS" ]]; then
      /bin/setfont $SETFONT_ARGS -C /dev/$DEV_TTY$n
      evaluate_retval
    fi
  done

  [[ -f $dropfile ]] && rm $dropfile
  STATUS_VARS="KEYMAP INCLUDEMAPS SETFONT_ARGS TTY_NUMS UNICODE_START DEV_TTY"
  for a in $STATUS_VARS; do
    echo "$a=\"${!a}\"" >> $dropfile
  done
}

stop()
{
  [[ "$TTY_NUMS" ]] && [[ "$SETFONT_ARGS" ]] &&
    required_executable /bin/setfont

  [[ -f $dropfile ]] && . $dropfile && rm $dropfile

  [[ "$KEYMAP$INCLUDEMAPS" ]] &&
    required_executable /bin/loadkeys &&
    /bin/loadkeys defkeymap 2>&1

  [[ "$UNICODE_START" ]] &&
    required_executable /bin/unicode_stop &&
    /bin/kbd_mode -a

  for n in $TTY_NUMS; do
    echo "Unloading settings for $DEV_TTY$n..."
    [[ "$UNICODE_START" ]] && echo -ne '\033%@' > /dev/$DEV_TTY$n
    if [[ "$SETFONT_ARGS" ]]; then
      /bin/setfont default8x16 -C /dev/$DEV_TTY$n
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
  echo "SETFONT_ARGS=\"$SETFONT_ARGS\""
  echo "TTY_NUMS=\"$TTY_NUMS\""
  echo "UNICODE_START=\"$UNICODE_START\""
}
