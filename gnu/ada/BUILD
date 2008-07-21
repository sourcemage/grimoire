# take multilib option from GCC
# ignore return value as it is only available on x86_64
persistent_read  gcc  GCC_MULTILIB  GCC_MULTILIB
# get CFLAGS and LDFLAGS gcc was compiled with, see bug #10087
persistent_read  gcc  GCC_CFLAGS   CFLAGS   &&
persistent_read  gcc  GCC_LDFLAGS  LDFLAGS  &&

# setup bootstrap ada compiler
ADA_PATH=${SOURCE3/.tar.bz2/}                   &&
PATH=$SOURCE_DIRECTORY/$ADA_PATH/usr/bin:$PATH  &&

if  [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "x86_64"  ]];  then
  OPTS="--build=x86_64-pc-linux-gnu  $OPTS"
fi  &&

export          CC="$SOURCE_DIRECTORY/$ADA_PATH/usr/bin/gnatgcc"                      &&
export INCLUDE_DIR="$SOURCE_DIRECTORY/$ADA_PATH/usr/lib/gnatgcc/$HOST/4.3.0/include"  &&
export     LIB_DIR="$SOURCE_DIRECTORY/$ADA_PATH/usr/lib/gnatgcc/$HOST/4.3.0/"         &&
export     LDFLAGS="-L${LIB_DIR}"

export    LIBRARY_PATH="$LIB_DIR"                             &&
export LD_LIBRARY_PATH="$LIB_DIR"                             &&
export   COMPILER_PATH="$SOURCE_DIRECTORY/$ADA_PATH/usr/bin"  &&

export ADA_OBJECTS_PATH="$LIB_DIR/adalib"      &&
export ADA_INCLUDE_PATH="$LIB_DIR/adainclude"  &&

cd $SOURCE_DIRECTORY.bld                                   &&
$SOURCE_DIRECTORY/configure                                \
             --host=$HOST                                  \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             --program-prefix=gnat                         \
             --enable-libada                               \
             --enable-languages="ada"                      \
             $GCC_MULTILIB                                 \
             $OPTS                                         &&

make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS"  \
     bootstrap
