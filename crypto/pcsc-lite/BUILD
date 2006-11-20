OPTS="$PCSC_MUSCLE                                    \
      $PCSC_EXADPU                                    \
      --enable-confdir=$INSTALL_ROOT/etc/pcsc-lite    \
      --enable-ipcdir=/var/run/ipc                    \
      --enable-runpid=/var/run                        \
      --docdir=$INSTALL_ROOT/usr/share/doc/pcsc-lite  \
      $OPTS"                                          &&

make_single    &&
default_build  &&
make_normal
