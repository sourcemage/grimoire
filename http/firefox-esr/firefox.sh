#!/bin/sh
# First check if this variable is already set 
# then if not set, check it (maybe), then set it 
#
# Set MOZILLA_FIVE_HOME for packages which need
# the mozilla libs (e.g. monodevelop)
#

if  [  -z  "$MOZILLA_FIVE_HOME" -a  !  -f  /etc/profile.d/mozilla.sh  ];  then
  MOZILLA_FIVE_HOME=/usr/lib/firefox
fi  &&

export  MOZILLA_FIVE_HOME
