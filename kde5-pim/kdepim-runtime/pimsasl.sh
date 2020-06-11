#!/bin/bash
if [ "$USER" != "root" ];then
# enable sasl to find plugins  for gmail, etc
  export SASL_PATH+=":/usr/lib/sasl2"
fi
