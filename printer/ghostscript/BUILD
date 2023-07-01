CFLAGS+=" -Wno-unused-but-set-variable -Wno-unused-variable -Wno-maybe-uninitialized"
# need a comma separated list
OPTS="--with-drivers=`echo ${GS_PRINTERS} | \
      sed "s/  */ /g;s/^ *//;s/ *$/ /;s/^NONE //;s/ /,/g"`JAPAN,FILES \
      --enable-dynamic --disable-hidden-visibility${OPTS}" &&

# -s causes libgs.so to be fully stripped
LDFLAGS+=' '
LDFLAGS="${LDFLAGS//-s }"

LIBS+=" -lz" default_build &&

if [[ $GS_LIBGS == y ]]; then
  make so
fi
