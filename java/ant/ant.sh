#!/bin/bash
# First check if this variable is already set
# then if not set, check it (maybe), then set it

if  [ -z "$ANT_HOME" ] ; then
  source /etc/profile.d/java.sh

  ANT_HOME=/opt/ant
fi

export ANT_HOME
export PATH=$PATH:$ANT_HOME/bin
