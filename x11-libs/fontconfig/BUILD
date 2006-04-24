aclocal   &&
autoconf  &&
sedit  's/`date`/`date --utc`/'  configure  &&
OPTS="$OPTS --with-add-fonts=/usr/X11R6/lib/X11/fonts/TTF,/usr/X11R6/lib/X11/fonts/Type1"  &&

make_single    &&
default_build  &&
make_normal
