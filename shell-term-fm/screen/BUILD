OPTS="$OPTS --with-sys-screenrc=/etc/screenrc"  &&
CFLAGS="$CFLAGS -std=gnu89" &&
# Avoid world-writable ptys! Even with the patches from OpenSUSE.
OPTS="$OPTS -with-pty-mode=0620 --with-pty-group=5" &&
if [[ $SCREEN_256COLOR == "y" ]]; then
  OPTS+=" --enable-colors256"
fi &&
default_build
