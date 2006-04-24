# DEBUG=-DNDEBUG is needed to get the spell compiling
# However the variable must not be exported otherwise
# Sorcery will create a /-DNDEBUG file at the end of install
OPTS="DEBUG=-DNDEBUG --libexecdir=/usr/lib\
      $OPTS"          &&

export  OPTIMIZER=$CFLAGS  &&

default_build
