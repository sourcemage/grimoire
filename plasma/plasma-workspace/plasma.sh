#!/bin/bash
if [ "$USER" != "root" ];then
# temporary runtime directories
export XDG_RUNTIME_DIR=${TMPDIR-/tmp}/plasma-$USER

# Ensure that they exist
mkdir -p $XDG_RUNTIME_DIR -m7700

fi

