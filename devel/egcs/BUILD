patch -p1 < $SCRIPT_DIRECTORY/egcs-1.1.2-glibc-2.2.patch           &&
sedit  's:#!/bin/sh:#!/bin/bash:'  $SOURCE_DIRECTORY/configure     &&
sedit  's:MT_CFLAGS = .*:MT_CFLAGS =:'  libio/config/mtsafe.mt     &&
sedit  's:MT_CFLAGS = .*:MT_CFLAGS =:'  libstdc++/config/linux.mt  &&

(
# running this in a subshell so the hack doesn't get a chance to leak outside
# of this spell

# evil hack (tm)
# this convinces sorcery to give us the gcc 2.x architecture flags,
# required because egcs doesn't know the newer ones
function use_gcc2 () {
  return 0
}             &&
optimize      &&

./configure  --host=$BUILD       \
             --prefix=/opt/egcs  \
             --enable-shared     \
       $OPTS                     &&
make  bootstrap
)
