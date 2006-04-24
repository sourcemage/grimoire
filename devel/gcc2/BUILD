bunzip2  -cd  $SCRIPT_DIRECTORY/gcc-2.95.3-2.patch.bz2  |
patch  -p 1  &&
sedit  's:#!/bin/sh:#!/bin/bash:'  $SOURCE_DIRECTORY/configure     &&
sedit  's:MT_CFLAGS = .*:MT_CFLAGS =:'  libio/config/mtsafe.mt     &&
sedit  's:MT_CFLAGS = .*:MT_CFLAGS =:'  libstdc++/config/linux.mt  &&

if    [  "$PASCAL"  ==  "y"  ]
then  sedit  "s/read junk//"  gcc/p/config-lang.in  &&
      sedit  's/for f in `cd p/for f in `cd $(srcdir)\/p/'  gcc/p/Make-lang.in
fi

cd $SOURCE_DIRECTORY.bld              &&

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

$SOURCE_DIRECTORY/configure           \
             --host=$BUILD            \
             --prefix=${INSTALL_ROOT}/opt/gcc2       \
             --enable-shared          \
             $LANGS                   \
             $OPTS                    &&
make  bootstrap
)
