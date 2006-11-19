./configure  &&
if [[ $SIMPLEINIT_NLS == y ]]; then
sedit 'd/#define HAVE_locale_h/' defines.h
fi
make  OPT="$CFLAGS"
