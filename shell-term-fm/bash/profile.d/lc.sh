#!/bin/sh
# Source the locale config and export all variables that are set.

. /etc/sysconfig/locale

for i in LANG LC_CTYPE LC_NUMERIC LC_TIME LC_COLLATE LC_MONETARY \
LC_MESSAGES LC_PAPER LC_NAME LC_ADDRESS LC_TELEPHONE LC_MEASUREMENT \
LC_ALL; do
  eval [ \"'$'$i\" ] && export $i
done
