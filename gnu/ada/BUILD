# take multilib option from GCC
# ignore return value as it is only available on x86_64
persistent_read  gcc  GCC_MULTILIB  GCC_MULTILIB
# get CFLAGS and LDFLAGS gcc was compiled with, see bug #10087
persistent_read  gcc  GCC_CFLAGS   CFLAGS   &&
persistent_read  gcc  GCC_LDFLAGS  LDFLAGS  &&

local OLD_CFLAGS="$CFLAGS"  &&
# setup bootstrap ada compiler
cd $SOURCE_DIRECTORY/gnat-3.15p-i686-pc-linux-gnu-bin  &&
mkdir -p  $SOURCE_DIRECTORY/gnat-bin                   &&
make  ins-all  prefix=$SOURCE_DIRECTORY/gnat-bin       &&
PATH=$SOURCE_DIRECTORY/gnat-bin/bin:$PATH              &&
CFLAGS=""                                              &&

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

CFLAGS="$OLD_CFLAGS"  &&
# bootstrapping with gnat-bin needs different CFLAGS for the stage1 compile
make CFLAGS="" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap
