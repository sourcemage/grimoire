#!/bin/bash
if [ "$USER" != "root" ];then
# enable sasl to find plugins  for gmail, etc
  export SASL_PATH+=":/opt/qt5/lib/sasl2"
fi
