CFLAGS+=" -Wno-unused-but-set-variable -Wno-unused-variable -Wno-maybe-uninitialized"
# need a comma separated list
OPTS="--with-drivers=`echo ${GS_PRINTERS} | \
      sed "s/  */ /g;s/^ *//;s/ *$/ /;s/^NONE //;s/ /,/g"`JAPAN,FILES \
      --enable-dynamic ${GS_OMNI} --without-luratech  ${OPTS}" &&

LIBS+=" -lz" default_build &&

if [[ $GS_LIBGS == y ]]; then
  make so
fi
