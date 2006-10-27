
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure.rb --prefix=${INSTALL_ROOT}/usr              \
               --bindir=${INSTALL_ROOT}/usr/bin          \
               --libdir=${INSTALL_ROOT}/usr/lib          \
               --includedir=${INSTALL_ROOT}/usr/include  \
               --datadir=${INSTALL_ROOT}/usr/share       \
               --mandir=${INSTALL_ROOT}/usr/share/man    \
               --enable-shared                           \
               $OPTS                                     &&
make

