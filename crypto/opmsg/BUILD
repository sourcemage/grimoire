if [[ $(get_spell_provider $SPELL SSL) == "libressl" ]]; then
  DEFS="-DHAVE_LIBRESSL -DHAVE_BN_GENCB_NEW=0 ${CFLAGS}"
fi &&

cd src &&
make DEFS="${DEFS}" LDFLAGS="${LDFLAGS}" &&

if [[ ${OPMSG_CONTRIB} == y ]]; then
  make DEFS="${DEFS}" LDFLAGS="${LDFLAGS}" contrib
fi
