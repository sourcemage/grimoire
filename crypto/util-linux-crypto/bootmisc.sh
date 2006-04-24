#!/bin/sh

dmesg  >  /var/log/dmesg
touch     /var/run/utmp
