export CPPFLAGS="$CPPFLAGS -I/usr/include/libpng12"  &&
# bug #12668
export CFLAGS="${CFLAGS/-O3/-Os}"                    &&
# Small typo preventing to compile - to be remove in next version I guess
sed -i 's/gtk-mdedia-next-rtl/gtk-media-next-rtl/' gtk/Makefile.in  &&
default_build
