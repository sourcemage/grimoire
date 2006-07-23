#!/bin/bash
# First check if this variable is already set
# then if not set, check it (maybe), then set it 

if  [ -z "$PKG_CONFIG_PATH" ] ; then
	PKG_CONFIG_PATH="/usr/lib/pkgconfig:/usr/share/pkgconfig"
fi
export PKG_CONFIG_PATH
