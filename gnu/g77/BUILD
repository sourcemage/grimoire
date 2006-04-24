# something's broken in its gcc version detection
sedit  "s/\$(gcc_version)/$VERSION/"  $SOURCE_DIRECTORY/libf2c/Makefile.in  &&
cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                                \
             --host=$HOST                                  \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             --enable-languages=f77                        \
             $OPTS                                         &&

make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap
