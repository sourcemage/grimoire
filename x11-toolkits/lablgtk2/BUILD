[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"

make_single    &&
default_build  &&
make  opt      &&
make_normal
