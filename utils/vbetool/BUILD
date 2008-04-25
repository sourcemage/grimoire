if [[ ${SMGL_COMPAT_ARCHS[1]} == "x86_64" ]]
then
  OPTS="--with-x86emu  \
        $OPTS"
fi  &&

LDFLAGS="$LDFLAGS -lz"  &&

default_build
