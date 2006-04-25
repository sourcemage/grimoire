cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                                \
             --host=$HOST                                  \
             --prefix=${INSTALL_ROOT}/opt/gcc-cvs                  \
             --infodir=${INSTALL_ROOT}/opt/gcc-cvs/info      \
             --mandir=${INSTALL_ROOT}/opt/gcc-cvs/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
	     --enable-languages=c			   \
	     --disable-werror				   \
             $MULTILIB $OPTS                              &&

make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     bootstrap
