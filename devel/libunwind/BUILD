if [[ $LIBUNWIND_BRANCH == scm ]]; then
mkdir -p config &&
libtoolize --copy &&
aclocal &&
autoheader &&
automake --add-missing --copy &&
autoconf
fi &&
case "$HOST" in
*-musl)
  # FIXME: execinfo not available on musl
  OPTS+=" --disable-tests"
  ;;
esac &&
default_build
