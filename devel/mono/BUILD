if [ "${HOST%%-*}" == x86_64 ]; then
  CFLAGS="${CFLAGS//-[fD]PIC/}"
fi  &&

OPTS="--with-tls=pthread $OPTS --build=${BUILD}"

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

make_single    &&
default_build  &&
make_normal
