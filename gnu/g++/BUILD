persistent_read gmp GMP_BUILD_ARCH GMP_BUILD_ARCH         &&
persistent_read mpfr MPFR_BUILD_ARCH MPFR_BUILD_ARCH      &&

if [[ $GMP_BUILD_ARCH  != ${SMGL_COMPAT_ARCHS[4]}
   || $MPFR_BUILD_ARCH != ${SMGL_COMPAT_ARCHS[4]} ]]; then
  message "${PROBLEM_COLOR}" 1>&2 &&
  message "gmp and/or mpfr have been built with a different archspec, building g++ now" 1>&2 &&
  message "would result in a broken compiler" 1>&2 &&
  message "${DEFAULT_COLOR}" 1>&2
  return 1
fi                                                        &&

# take multilib option (and nolib64 option) from GCC
# ignore return value as they are only available on x86_64
persistent_read  gcc  GCC_MULTILIB  GCC_MULTILIB
persistent_read  gcc  GCC_NOLIB64   GCC_NOLIB64
# get CFLAGS and LDFLAGS gcc was compiled with, see bug #10087
persistent_read  gcc  GCC_CFLAGS   CFLAGS   &&
persistent_read  gcc  GCC_LDFLAGS  LDFLAGS  &&

if  [[  "$ARCHITECTURE"  ==  "pentium4"  ||
        "$ARCHITECTURE"  ==  "pentium-m"  ]];  then
  CXXFLAGS=${CXXFLAGS//-ffast-math/}
fi  &&

if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=$HOST $OPTS"
else
  OPTS="--build=$HOST $OPTS"
fi  &&

sedit "s/lib64/lib/" gcc/config/i386/linux64.h             &&

if [[ "$GCC_NOLIB64" == 'y' ]]; then
  # tell gcc (g++) to target binaries to expect the linker in /lib instead of /lib64
  sedit "s/lib64/lib/" gcc/config/i386/t-linux64
fi                                                         &&

cd $SOURCE_DIRECTORY.bld                                   &&
# Ignore any installed g++, it could botch up configure!
CXX=/bin/false $SOURCE_DIRECTORY/configure                 \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             --enable-languages=c++                        \
             $GCC_MULTILIB                                 \
             $OPTS                                         &&

make_single                                                    &&
make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap-lean
