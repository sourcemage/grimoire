OPTS="$PCSC_MUSCLE                                  \
      $PCSC_EXADPU                                  \
      --enable-confdir=$INSTALL_ROOT/etc/pcsc-lite  \
      --enable-ipcdir=/var/run/ipc                  \
      --enable-runpid=/var/run                      \
      $OPTS"                                        &&

make_single    &&
default_build  &&
make_normal
