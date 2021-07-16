case "$HOST" in
  (*-musl)
    CFLAGS+=" $(pkg-config libtirpc --cflags)" &&
    LIBS+=" $(pkg-config libtirpc --libs)" &&
    OPTS+=' xinetd_cv_type_rlim_t=yes'
esac &&
LIBS+=" $LDFLAGS"  &&  # Makes stripping work
export LIBS &&

OPTS="$XINETD_IPV6     \
      $XINETD_LOADAVG  \
      $OPTS"           &&

default_build
