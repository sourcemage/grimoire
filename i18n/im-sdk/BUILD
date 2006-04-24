(
  BUILDDIRS="lib/EIMIL lib/iiimp lib/iiimcf \
    iiimsf leif iiimxcf/xiiimp.so iiimxcf/htt_xbe iiimgcf"

  (
    # this makes it compile with libiconv installed
    cp lib/CSConv/iconv/iconv.h include/   &&

    cd lib/CSConv                          &&
    ./configure \
      --prefix=$INSTALL_ROOT/usr/lib/im \
      --without-libiconv-prefix \
      $OPTS  &&
    make
  )                                        &&

  for dir in $BUILDDIRS; do
  (
    cd $dir                                &&
    ./configure \
      --prefix=$INSTALL_ROOT/usr \
      --sysconfdir=$INSTALL_ROOT/etc \
      --localstatedir=$INSTALL_ROOT/var \
      --libdir=$INSTALL_ROOT/usr/lib \
      --without-libiconv-prefix \
      $OPTS                                &&
    make
  ) || return 1
  done                         &&

  prepare_install              &&

  (
    cd lib/CSConv              &&
    make install
  )                            &&

  for dir in $BUILDDIRS; do
  (
    cd $dir                    &&
    make install
  ) || return 1
  done                         &&
  
  # move config file to a sane place
  cd $INSTALL_ROOT/usr/lib/im                       &&
  if [ ! -f $INSTALL_ROOT/etc/im/htt.conf ] ; then
    mkdir -p $INSTALL_ROOT/etc/im                   &&
    mv htt.conf $INSTALL_ROOT/etc/im/
  else
    rm -f htt.conf
  fi                                                &&
  ln -sf /etc/im/htt.conf htt.conf
) >$C_FIFO 2>&1
