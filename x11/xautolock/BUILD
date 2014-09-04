if [[ $XAUTOLOCK_READXDEF == y ]]; then
  CFLAGS="-DReadXdefaultsFile ${CFLAGS}"
fi &&

xmkmf -a &&

make EXTRA_LDOPTIONS="${LDFLAGS}" CDEBUGFLAGS="${CFLAGS}"
