#!/bin/sh
#
# Source Mage init.d install information
# SMGL-START:2 3 4 5:S40
# SMGL-STOP:0 1 6:K60
#

source /etc/init.d/functions

BIN_PATH=/usr/sbin
CFG_FILE=/etc/iplog.conf
IFACE=eth0

case $1 in

    start)  
	echo  "Starting iplog, TCP/IP traffic logger."
	mkdir  -p  /var/run/iplog
	chown  iplog.iplog  /var/run/iplog -R
	loadproc  ${BIN_PATH}/iplog -i ${IFACE} -u iplog -g iplog      
	;;
	
     stop)  
	echo  "Stoping  iplog, TCP/IP traffic logger."
	${BIN_PATH}/iplog -k
	evaluate_retval
	;;
	
 restart)                                                                                              
	echo  "Restarting iplog"
	${BIN_PATH}/iplog -R
	evaluate_retval
	;;
	
       *)
        echo  "Usage: $0 {start|stop|restart}"
        ;;

esac
