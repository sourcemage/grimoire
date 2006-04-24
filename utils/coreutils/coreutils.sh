#!/bin/bash
# make coreutils tools not fail on common commands that happen to be left out
# of the posix standard (e.g. tail -1)
export _POSIX2_VERSION=199209
