# take multilib option from GCC
# ignore return value as it is only available on x86_64
persistent_read  gcc  GCC_MULTILIB  GCC_MULTILIB
# get CFLAGS and LDFLAGS gcc was compiled with, see bug #10087
persistent_read  gcc  GCC_CFLAGS   CFLAGS   &&
persistent_read  gcc  GCC_LDFLAGS  LDFLAGS  &&

# setup bootstrap ada compiler
ADA_PATH=gnat-4.1.1-i386-pc-linux-gnu       &&
PATH=$SOURCE_DIRECTORY/$ADA_PATH/bin:$PATH  &&

cd $SOURCE_DIRECTORY.bld                                   &&
$SOURCE_DIRECTORY/configure                                \
             --host=$HOST                                  \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             --enable-languages=ada                        \
             $GCC_MULTILIB                                 \
             $OPTS                                         &&

make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap
