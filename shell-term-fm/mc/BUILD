if [ "$MC_GLIB" == "glib" ]; then
  OPTS="$OPTS --with-glib12"
fi                                       &&
./configure --prefix=${INSTALL_ROOT}/usr \
            --with-screen=ncurses        \
            $OPTS                        &&
make
