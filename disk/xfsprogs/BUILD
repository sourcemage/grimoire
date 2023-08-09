# DEBUG=-DNDEBUG is needed to get the spell compiling
# However the variable must not be exported otherwise
# Sorcery will create a /-DNDEBUG file at the end of install

disable_reject_underlinking &&

CFLAGS+=' -D_LARGEFILE64_SOURCE' && # to expose off64_t and related symbols

OPTS="DEBUG=-DNDEBUG \
  --libexecdir=$DEFAULT_ROOT/usr/lib \
  --sbindir=$DEFAULT_ROOT/sbin \
  $OPTS" &&

OPTIMIZER=$CFLAGS default_build
