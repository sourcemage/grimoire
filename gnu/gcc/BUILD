persistent_read gmp GMP_BUILD_ARCH GMP_BUILD_ARCH         &&
persistent_read mpfr MPFR_BUILD_ARCH MPFR_BUILD_ARCH      &&

if [[ $GMP_BUILD_ARCH  != ${SMGL_COMPAT_ARCHS[4]}
   || $MPFR_BUILD_ARCH != ${SMGL_COMPAT_ARCHS[4]} ]]; then
  message "${PROBLEM_COLOR}" 1>&2 &&
  message "gmp and/or mpfr have been built with a different archspec, building gcc now" 1>&2 &&
  message "would result in a broken compiler" 1>&2 &&
  message "${DEFAULT_COLOR}" 1>&2
  return 1
fi                                                        &&

# install gcc libraries to /lib instead of /lib64
sedit "s/lib64/lib/" gcc/config/i386/linux64.h            &&
if [[ "$GCC_NOLIB64" == 'y' ]]; then
  # tell gcc to target binaries to expect the linker in /lib instead of /lib64
  sedit "s/lib64/lib/" gcc/config/i386/t-linux64           
fi                                                        &&

if  [[ "$ARCHITECTURE"  ==  "pentium4"  ||
       "$ARCHITECTURE"  ==  "pentium-m"  ]];  then
  CFLAGS=${CFLAGS//-ffast-math/}
  CXXFLAGS=${CXXFLAGS//-ffast-math/}
fi  &&

# fixes seg-fault on libiberty/splay.c in v 4.3.2
CFLAGS="-O1 $CFLAGS"                                      &&

if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=$HOST $OPTS"
else
  OPTS="--build=$HOST $OPTS"
fi  &&

# store CFLAGS and LDFLAGS persistently so they can be read by the other
# split spells later, see bug #10087
GCC_CFLAGS="$CFLAGS"                   &&
GCC_LDFLAGS="$LDFLAGS"                 &&
persistent_add GCC_CFLAGS GCC_LDFLAGS  &&

cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                                \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --with-system-zlib                            \
             $GCC_MULTILIB $OPTS                          &&

make_single                                                    &&
make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap-lean
