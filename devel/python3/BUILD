OPTS="--enable-shared  $PYTHON3_OPTS $OPTS" &&
OPTS="--with-ensurepip=no $OPTS"            &&

OPTS+=" --enable-optimizations"             &&
OPTS+=" --with-lto"                         &&
OPTS+=" --with-computed-gotos"              &&

EXTRA_CFLAGS="$CFLAGS" default_build
