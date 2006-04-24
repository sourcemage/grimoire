#!/bin/bash
# Enhancing support for locale support
# First source the locale config then
# if a var is set set it...

. /etc/sysconfig/locale

function export_if_set() {

#if the variable whose name is in $1 is not empty

if [[ -n ${!1} ]] 
then
  export $1
fi
}

LOCALE_VARS="LANG LC_CTYPE LC_NUMERIC LC_TIME LC_COLLATE \
LC_MONETARY LC_MESSAGES LC_PAPER LC_NAME \
LC_ADDRESS LC_TELEPHONE LC_MEASUREMENT LC_ALL"

for i in $LOCALE_VARS
do
  export_if_set "$i"
done
