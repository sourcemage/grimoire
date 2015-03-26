if [[ $XAUTOLOCK_READXDEF == y ]]; then
  CFLAGS="-DReadXdefaultsFile ${CFLAGS}"
fi &&

check_tmp_noexec /tmp &&
xmkmf -a &&
check_tmp_noexec /tmp &&

make EXTRA_LDOPTIONS="${LDFLAGS}" CDEBUGFLAGS="${CFLAGS}"
