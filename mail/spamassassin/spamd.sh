#!/bin/bash
#

# See how we were called.
case "$1" in
  start)
	echo "starting spamd"
	spamd -d	
	sleep 3
	thePid=`ps ax | grep spamd | grep perl | sed "s/^ *//g" | cut -d\  -f1`
	echo $thePid > /var/run/spamd.pid
	;;
  stop)
	echo "stopping spamd"
	thePid=`ps ax | grep spamd | grep perl | sed "s/^ *//g" | cut -d\  -f1`
	kill -15 $thePid
	rm -f /var/run/spamd.pid
	;;
  restart|reload)
	$0 stop
	$0 start
	;;
  status)
        echo -n "spamd is "
        if [ `ps ax | grep spamd | grep perl | sed "s/^ *//g" | cut -d\  -f1` == "" ]; then
          echo -n "not "
        fi
	echo "running."
        ;;
  *)
        echo "Usage: spamd {start|stop|restart|status}"
        exit 1
esac

exit 0

