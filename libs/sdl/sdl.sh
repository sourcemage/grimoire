#!/bin/bash

# Source variables from config file
. /etc/sysconfig/sdl

# Export all set variables
while read a; do
  [[ "$a" =~ "^[^\#]*=" ]] && export $(expr $a : "\(^[^=]*\).*$")
done < /etc/sysconfig/sdl
