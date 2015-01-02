if [[ $LIBUNWIND_BRANCH == scm ]]; then
mkdir -p config &&
libtoolize --copy &&
aclocal &&
autoheader &&
automake --add-missing --copy &&
autoconf
fi &&
default_build
