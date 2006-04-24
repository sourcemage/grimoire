#!/bin/sh
# mosstatd     This shell script takes care of starting and stopping \
#              the mosstatd daemon.


PROGRAM=/usr/bin/mosstatd
RUNLEVEL=3
NEEDS="+remote_fs +network +portmap openmosix"

. /etc/init.d/smgl_init

