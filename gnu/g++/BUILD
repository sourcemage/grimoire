# take multilib option (and nolib64 option) from GCC
# ignore return value as they are only available on x86_64
persistent_read  gcc  GCC_MULTILIB  GCC_MULTILIB
persistent_read  gcc  GCC_NOLIB64   GCC_NOLIB64
# get CFLAGS and LDFLAGS gcc was compiled with, see bug #10087
persistent_read  gcc  GCC_CFLAGS   CFLAGS   &&
persistent_read  gcc  GCC_LDFLAGS  LDFLAGS  &&

sedit "s/lib64/lib/" gcc/config/i386/linux64.h             &&

if [[ "$GCC_NOLIB64" == 'y' ]]; then
  # tell gcc (g++) to target binaries to expect the linker in /lib instead of /lib64
  sedit "s/lib64/lib/" gcc/config/i386/t-linux64
fi                                                         &&

cd $SOURCE_DIRECTORY.bld                                   &&
$SOURCE_DIRECTORY/configure                                \
             --host=$HOST                                  \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             --enable-languages=c++                        \
             $GCC_MULTILIB                                 \
             $OPTS                                         &&

make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap
