#!/bin/sh
# First check if this variable is already set
# then if not set, check it (maybe), then set it

if  [ -z "$EDITOR" ] ; then
        EDITOR="diakonos"
fi

export EDITOR

