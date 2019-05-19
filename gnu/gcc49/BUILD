# using -pipe causes spurious test-suite failures
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=48565
CFLAGS=${CFLAGS/-pipe/} &&
CXXFLAGS=${CXXFLAGS/-pipe/} &&

persistent_read gmp GMP_BUILD_ARCH GMP_BUILD_ARCH &&
persistent_read mpfr MPFR_BUILD_ARCH MPFR_BUILD_ARCH &&

if [[ $GMP_BUILD_ARCH  != ${SMGL_COMPAT_ARCHS[4]}
   || $MPFR_BUILD_ARCH != ${SMGL_COMPAT_ARCHS[4]} ]]; then
  message "${PROBLEM_COLOR}" 1>&2 &&
  message "gmp and/or mpfr have been built with a different archspec, building gcc now" 1>&2 &&
  message "would result in a broken compiler" 1>&2 &&
  message "${DEFAULT_COLOR}" 1>&2
  return 1
fi &&

# install gcc libraries to /lib instead of /lib64
sedit "s/lib64/lib/" gcc/config/i386/linux64.h &&
# tell gcc to target binaries to expect the linker in /lib instead of /lib64
sedit "s/lib64/lib/" gcc/config/i386/t-linux64 &&

if  [[ "$ARCHITECTURE"  ==  "pentium4"  ||
       "$ARCHITECTURE"  ==  "pentium-m"  ]];  then
  CFLAGS=${CFLAGS//-ffast-math/}
  CXXFLAGS=${CXXFLAGS//-ffast-math/}
fi &&

if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=$HOST $OPTS"
else
  OPTS="--build=$HOST $OPTS"
fi &&

OPTS+=" --prefix=${INSTALL_ROOT}/opt/gcc49" &&
OPTS+=" --mandir=${INSTALL_ROOT}/opt/gcc49/share/man" &&
OPTS+=" --infodir=${INSTALL_ROOT}/opt/gcc49/share/info" &&

OPTS+=" --enable-bootstrap" &&
OPTS+=" --enable-checking=release" &&
OPTS+=" --enable-clocale=gnu" &&
OPTS+=" --enable-gnu-unique-object" &&
OPTS+=" --enable-languages=c,c++,lto" &&
OPTS+=" --enable-linker-build-id" &&
OPTS+=" --enable-lto" &&
OPTS+=" --enable-plugin" &&
OPTS+=" --enable-shared" &&
OPTS+=" --enable-threads=posix" &&
OPTS+=" --enable-__cxa_atexit" &&
OPTS+=" --disable-libgcj" &&
OPTS+=" --disable-libquadmath" &&
OPTS+=" --disable-libstdcxx-pch" &&
OPTS+=" --disable-werror" &&
OPTS+=" --with-bugurl=http://bugs.sourcemage.org" &&
OPTS+=" --with-linker-hash-style=gnu" &&
OPTS+=" --without-cloog" &&
OPTS+=" $GCC_MULTILIB" &&

cd $SOURCE_DIRECTORY.bld &&
$SOURCE_DIRECTORY/configure $OPTS &&
make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" bootstrap-lean
