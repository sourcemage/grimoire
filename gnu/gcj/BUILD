# take multilib option from GCC
# ignore return value as it is only available on x86_64
persistent_read  gcc  GCC_MULTILIB  GCC_MULTILIB
# get CFLAGS and LDFLAGS gcc was compiled with, see bug #10087
persistent_read  gcc  GCC_CFLAGS   CFLAGS   &&
persistent_read  gcc  GCC_LDFLAGS  LDFLAGS  &&

# when updating this spell please check if this is still necessary:
if [[ $GCJ_AWT == y ]]; then
  CFLAGS="$CFLAGS -I${INSTALL_ROOT}/usr/include/freetype2"
fi &&

if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=$HOST $OPTS"
else
  OPTS="--build=$HOST $OPTS"
fi  &&

sedit "s/lib64/lib/" gcc/config/i386/linux64.h             &&

cd $SOURCE_DIRECTORY.bld                                   &&
$SOURCE_DIRECTORY/configure                                \
             --prefix=${INSTALL_ROOT}/usr                  \
             --libdir=${INSTALL_ROOT}/usr/lib              \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             --enable-languages=java                       \
             $GCC_MULTILIB                                 \
             $OPTS                                         &&

make_single                                                    &&
make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap-lean
