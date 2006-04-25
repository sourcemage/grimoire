cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                               \
             --host=$HOST                                 \
           --prefix=${INSTALL_ROOT}/opt/gcc34             \
          --infodir=${INSTALL_ROOT}/opt/gcc34/share/info  \
           --mandir=${INSTALL_ROOT}/opt/gcc34/share/man   \
   --enable-threads=posix                                 \
 --enable-languages=c,c++                                 \
       $GCC_MULTILIB $OPTS                                &&

make  bootstrap
