#!/bin/bash
# Added by /usr/sbin/smgl.install
# First check if this variable is already set
# then if not set, check it (maybe), then set it

if  [ -z "$LANG" ] ; then
        LANG="en_US"
fi

export LANG

