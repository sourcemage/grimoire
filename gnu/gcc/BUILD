# cc1 compilation fails if the file blocks limit is too low
ulimit -f unlimited &&

. "$GRIMOIRE/FUNCTIONS" &&
# using -pipe causes spurious test-suite failures
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=48565
CFLAGS=${CFLAGS/-pipe/}     &&
CXXFLAGS=${CXXFLAGS/-pipe/} &&

if list_find "$GCC_COMPILER" "fortran"; then
  OPTS+=" --enable-libquadmath"
else
  OPTS+=" --disable-libquadmath"
fi &&

if list_find "$GCC_COMPILER" "jit"; then
  OPTS+=" --enable-host-shared"
fi &&

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
sedit "s/lib64/lib/" gcc/config/i386/linux64.h  &&
# tell gcc to target binaries to expect the linker in /lib instead of /lib64
sedit "s/lib64/lib/" gcc/config/i386/t-linux64  &&

if  [[ "$ARCHITECTURE"  ==  "pentium4"  ||
       "$ARCHITECTURE"  ==  "pentium-m"  ]];  then
  CFLAGS=${CFLAGS//-ffast-math/}
  CXXFLAGS=${CXXFLAGS//-ffast-math/}
fi  &&

disable_fortify_source         &&
disable_cf_protection          &&

# fixes seg-fault on libiberty/splay.c in v 4.3.2
if is_version_less $(installed_version $SPELL) 5.0.0; then
  CFLAGS="-O1 $CFLAGS"
fi &&

if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=$HOST $OPTS"
else
  OPTS="--build=$HOST $OPTS"
fi  &&

# store CFLAGS and LDFLAGS persistently so they can be read by the other
# split spells later, see bug #10087
GCC_CFLAGS="$CFLAGS"  &&
GCC_LDFLAGS="$LDFLAGS"  &&
persistent_add GCC_CFLAGS GCC_LDFLAGS  &&
# when updating this spell please check if this is still necessary:
if [[ $GCJ_AWT == y ]]; then
  CFLAGS="$CFLAGS -I${INSTALL_ROOT}/usr/include/freetype2"
fi  &&

if list_find "$GCC_COMPILER" "ada" ; then
  # setup bootstrap ada compiler
  ADA_PATH=${SOURCE13/.tar.bz2/}  &&
  PATH=$SOURCE_DIRECTORY/$ADA_PATH/bin:$PATH  &&

  export CC="$SOURCE_DIRECTORY/$ADA_PATH/usr/bin/gcc" &&

  export INCLUDE_DIR="$SOURCE_DIRECTORY/$ADA_PATH/usr/lib/gcc/$HOST/${VERSION13}/include"  &&
  export LIB_DIR="$SOURCE_DIRECTORY/$ADA_PATH/usr/lib/gcc/$HOST/${VERSION13}/"  &&
  export LDFLAGS="-L${LIB_DIR}"  &&
  export LIBRARY_PATH="$LIB_DIR"  &&
  export LD_LIBRARY_PATH="$LIB_DIR"  &&
  export COMPILER_PATH="$SOURCE_DIRECTORY/$ADA_PATH/usr/bin"  &&

  export ADA_OBJECTS_PATH="$LIB_DIR/adalib"  &&
  export ADA_INCLUDE_PATH="$LIB_DIR/adainclude"  &&

  OPTS="--enable-libada $OPTS"

fi  &&

OPTS="$GCJ_HOME $OPTS"                                             &&
OPTS="--prefix=${INSTALL_ROOT}/usr $OPTS"                          &&
OPTS="--libdir=${INSTALL_ROOT}/usr/lib $OPTS"                      &&
OPTS="--libexecdir=${INSTALL_ROOT}/usr/lib $OPTS"                  &&
OPTS="--mandir=${INSTALL_ROOT}/usr/share/man $OPTS"                &&
OPTS="--infodir=${INSTALL_ROOT}/usr/share/info $OPTS"              &&
OPTS="--with-bugurl=http://bugs.sourcemage.org $OPTS"              &&
OPTS="--enable-languages=${GCC_COMPILER// /,},lto $OPTS"           &&
OPTS="--enable-shared $OPTS"                                       &&
OPTS="--enable-threads=posix $OPTS"                                &&
OPTS="--enable-__cxa_atexit $OPTS"                                 &&
OPTS="--disable-libunwind-exceptions $OPTS"                        &&
OPTS="--enable-clocale=gnu $OPTS"                                  &&
OPTS="--disable-libstdcxx-pch $OPTS"                               &&
OPTS="--enable-bootstrap $OPTS"                                    &&
OPTS="--enable-gnu-unique-object $OPTS"                            &&
OPTS="--enable-linker-build-id $OPTS"                              &&
if [[ "$GCC_CLOOG" == "y" ]]; then
  OPTS="--enable-cloog-backend=isl $OPTS"  &&
  OPTS="--disable-isl-version-check $OPTS"
else
  OPTS="--without-isl --without-cloog $OPTS"
fi &&
OPTS="--enable-plugin $OPTS"                                       &&
OPTS="--enable-install-libiberty $OPTS"                            &&
OPTS="--with-linker-hash-style=gnu $OPTS"                          &&
OPTS="--disable-werror $OPTS"                                      &&
OPTS="--enable-checking=release $OPTS"                             &&
OPTS="--enable-default-pie $OPTS"                                  &&
OPTS="--enable-default-ssp $OPTS"                                  &&
OPTS="--enable-cet=auto $OPTS"                                     &&
OPTS="--enable-lto $OPTS"                                          &&
OPTS="$GCC_MULTILIB $OPTS"                                         &&

case "$HOST" in
*-musl)
  OPTS="--disable-multilib $OPTS" &&
  OPTS="--disable-libmpx $OPTS" &&
  OPTS="--disable-libmudflap $OPTS" &&
  OPTS="--disable-libsanitizer $OPTS" &&
  OPTS="--disable-symvers $OPTS"
  ;;
esac &&

# https://sourceware.org/bugzilla/show_bug.cgi?id=21930
export glibcxx_cv_c99_math_cxx98=yes glibcxx_cv_c99_math_cxx11=yes &&

cd $SOURCE_DIRECTORY.bld                                              &&
$SOURCE_DIRECTORY/configure $OPTS                                     &&

if is_version_less $(installed_version $SPELL) 4.9.0; then
  if ! spell_ok gcc49; then
    message "${PROBLEM_COLOR}" 1>&2 &&
    message "This version of gcc needs gcc >= 4.9.0 to be able to compile. Spell" 1>&2 &&
    message "gcc49 is available to support this, but is not found to be installed." 1>&2 &&
    message "Please cast gcc49 first." 1>&2 &&
    message "${DEFAULT_COLOR}" 1>&2
    return 1
  fi
  PATH=/opt/gcc49/bin:$PATH make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" $GCC_TARGET
else
  make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" $GCC_TARGET
fi
