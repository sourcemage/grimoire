#!/bin/sh
# First check if this variable is already set
# then if not set, check it (maybe), then set it

if  [ -z "$PAGER" ] ; then
        PAGER="w3m"
fi

export PAGER

