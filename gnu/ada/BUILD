local OLD_CFLAGS="$CFLAGS"  &&
if [[ $SOURCE3 ]]; then
  # setup bootstrap ada compiler
  cd $SOURCE_DIRECTORY/gnat-3.15p-i686-pc-linux-gnu-bin  &&
  mkdir -p  $SOURCE_DIRECTORY/gnat-bin                   &&
  make  ins-all  prefix=$SOURCE_DIRECTORY/gnat-bin       &&
  PATH=$SOURCE_DIRECTORY/gnat-bin/bin:$PATH              &&
  CFLAGS=""
fi  &&
cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                                \
             --host=$HOST                                  \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             --enable-languages=ada                        \
             $OPTS                                         &&

if [[ $SOURCE3 ]]; then
  CFLAGS="$OLD_CFLAGS"  &&
  # bootstrapping with gnat-bin needs different CFLAGS for the stage1 compile
  make CFLAGS="" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
       profiledbootstrap
else
  make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
       profiledbootstrap
fi  &&
make -C gcc gnatlib gnattools
