#!/bin/bash
# If user has no local inputrc file, use global file if it exists

if [[ ! -f $HOME/.inputrc ]]  &&
   [[ -f /etc/inputrc ]];   then
  export INPUTRC=/etc/inputrc
fi
