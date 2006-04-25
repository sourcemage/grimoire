#!/bin/bash

if [ ! -e $HOME/.inputrc ]  &&
   [ -e /etc/inputrc ]; then
  export INPUTRC=/etc/inputrc
fi
