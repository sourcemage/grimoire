#!/bin/sh
#
#  gdm.sh  Load the GDM login manager at boot
#
#               Written for Source Mage GNU/Linux
#
#  Version:  @(#)gdm.sh  1.0.0  2002-10-02  Eric Sandall <eric@sandall.us>
#  Version:  @(#)gdm.sh  1.0.1  2003-03-28  Eric Sandall <eric@sandall.us>
#    Now properly kills all instances of gdm (since they are not just named gdm)
#

case  $1  in
          start)  echo "$1ing gdm"
                  gdm
                  ;;

           stop)  echo "$1ping gdm"
                  pkill  "^gdm*"
                  ;;

        restart)  stop   $0  &&
                  start  $0
                  ;;

              *)  echo "Usage: $0 {start|stop|restart}"
                  ;;
esac
