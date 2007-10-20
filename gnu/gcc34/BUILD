cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                               \
             --host=$HOST                                 \
           --prefix=${INSTALL_ROOT}/usr                   \
          --infodir=${INSTALL_ROOT}/usr/share/info        \
           --mandir=${INSTALL_ROOT}/usr/share/man         \
   --program-suffix=-${VERSION%.*}                        \
   --enable-threads=posix                                 \
 --enable-languages=c,c++                                 \
       $GCC_MULTILIB $OPTS                                &&

make  bootstrap &&
make  DESTDIR=$SOURCE_DIRECTORY.install install-no-fixedincludes
