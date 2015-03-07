OPTS="$LIBX11_OPTS $OPTS"  &&
# XXX -Os causes 1.5+ to link incorrectly to most applications because of
# missing symbols.
CFLAGS="${CFLAGS/-Os/-O2}" &&
default_build
