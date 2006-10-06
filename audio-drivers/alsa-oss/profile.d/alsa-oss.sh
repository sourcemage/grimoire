#!/bin/sh

[ -f /etc/sysconfig/alsa-oss ]  &&
  . /etc/sysconfig/alsa-oss     &&
  export  USE_AOSS_WRAPPER
