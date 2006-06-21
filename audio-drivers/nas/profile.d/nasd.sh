#!/bin/bash 
# First check if this variable is already set 
# then if not set, check it (maybe), then set it 

if [ -e /etc/sysconfig/nasd ] ; then
  . /etc/sysconfig/nasd
  if  [ -z "$AUDIOSERVER" ] ; then 
	AUDIOSERVER="tcp/$NAS_AUDIOSERVER:$NAS_PORT"
  fi &&
  export AUDIOSERVER
fi
