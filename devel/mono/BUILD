if [ "${HOST%%-*}" == x86_64 ]; then
  CFLAGS="${CFLAGS//-[fD]PIC/}"  &&
  OPTS="--with-tls=__thread $OPTS --build=${BUILD}"
else
  OPTS="--with-tls=pthread $OPTS --build=${BUILD}"
fi &&

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

make_single    &&
default_build  &&
make_normal
