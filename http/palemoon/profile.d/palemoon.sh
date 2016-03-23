#!/bin/sh
#
# First check if this variable is already set
# then if not set, check it (maybe), then set it
#
# Set MOZ_PLUGIN_PATH for Pale Moon which need
# the plugins (e.g. flash) in default path
#

if [ -z "$MOZ_PLUGIN_PATH" ]; then
	MOZ_PLUGIN_PATH="/usr/lib/palemoon/plugins"
fi &&

export MOZ_PLUGIN_PATH
