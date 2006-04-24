[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"

make_single           &&
make configure $OPTS  &&
make                  &&
make opt              &&
make_normal
