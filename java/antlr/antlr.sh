#!/bin/bash
# First check if this variable is already set
# then if not set, check it (maybe), then set it

if  [ -z "$CLASSPATH" ] ; then
        export CLASSPATH=/usr/share/antlr-ANTLR_VER/antlr.jar
fi

