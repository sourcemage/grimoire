case "$HOST" in
  (*-musl)
    OPTS+=' xinetd_cv_type_rlim_t=yes'
esac &&
CFLAGS+=" $(pkg-config libtirpc --cflags)" &&
LIBS+=" $(pkg-config libtirpc --libs)" &&
LIBS+=" $LDFLAGS"  &&  # Makes stripping work
export LIBS &&

OPTS="$XINETD_IPV6     \
      $XINETD_LOADAVG  \
      $OPTS"           &&

default_build
