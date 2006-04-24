#!/bin/bash 
# First check if this variable is already set 
# then if not set, check it (maybe), then set it 

if ! echo $LD_PRELOAD | grep -q libtrash.so &&  [ -e /usr/lib/libtrash.so ] ; then
	LD_PRELOAD="/usr/lib/libtrash.so"
fi 

export LD_PRELOAD


