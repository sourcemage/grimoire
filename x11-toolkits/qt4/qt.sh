#!/bin/bash 
# First check if this variable is already set 
# then if not set, check it (maybe), then set it 

if  [ -z "$QTDIR" ] ; then 
	QTDIR=/usr
fi 
export QTDIR

