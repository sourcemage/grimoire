#!/bin/sh

patch -p1 < "${SCRIPT_DIRECTORY}/installwatch-ld-preload.diff" &&
patch -p1 < "${SCRIPT_DIRECTORY}/installwatch-errno.diff"  &&
patch -p1 < "${SCRIPT_DIRECTORY}/installwatch-buffer.diff" &&
patch -p1 < "${SCRIPT_DIRECTORY}/installwatch-cflags.diff" &&
patch -p1 < "${SCRIPT_DIRECTORY}/installwatch-syslog.diff" &&

# If LIB is not defined, we do not have the bi-arch sorcery, so we
# define LIB

LIB="${LIB:-/lib}"
make PREFIX="${TRACK_ROOT}/usr" LIBDIR="${TRACK_ROOT}/usr/${LIB}"

