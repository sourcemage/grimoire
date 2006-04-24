#!/bin/sh
#
# Source Mage init.d install information
# SMGL-script-version=20030331
# SMGL-START:3 4 5:S33
# SMGL-STOP:0 1 2 6:K11
#

case $1 in
     start|restart  )  echo      "$1ing pglogd - Apache web server logger."
                      mkdir  -p  /var/log/pglogd
		      pkill  "^pglogd$"
                      pglogd -c /etc/pglogd.conf
                      ;;

     stop 	    )  echo      "$1ing pglogd - Apache web server logger."
		      pkill  "^pglogd$"
                      ;;

                  *)  echo      "Usage: $0 {start|stop|restart}"
                      ;;
esac
