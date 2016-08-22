# using -pipe causes spurious test-suite failures
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=48565
CFLAGS=${CFLAGS/-pipe/}     &&
CXXFLAGS=${CXXFLAGS/-pipe/} &&

if list_find "$GCC_COMPILER" "java"; then
  OPTS+=" --enable-libgcj" &&
  OPTS+=" --disable-plugin"
else
  OPTS+=" --disable-libgcj" &&
  OPTS+=" --enable-plugin"
fi &&

if list_find "$GCC_COMPILER" "fortran"; then
  OPTS+=" --enable-libquadmath"
else
  OPTS+=" --disable-libquadmath"
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

# fixes seg-fault on libiberty/splay.c in v 4.3.2
CFLAGS="-O1 $CFLAGS"  &&

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
  PATH=$SOURCE_DIRECTORY/$ADA_PATH/usr/bin:$PATH  &&

  export CC="$SOURCE_DIRECTORY/$ADA_PATH/bin/gcc" &&

  export INCLUDE_DIR="$SOURCE_DIRECTORY/$ADA_PATH/lib/gcc/$HOST/${VERSION13}/include"  &&
  export LIB_DIR="$SOURCE_DIRECTORY/$ADA_PATH/lib/gcc/$HOST/${VERSION13}/"  &&
  export LDFLAGS="-L${LIB_DIR}"  &&
  export LIBRARY_PATH="$LIB_DIR"  &&
  export LD_LIBRARY_PATH="$LIB_DIR"  &&
  export COMPILER_PATH="$SOURCE_DIRECTORY/$ADA_PATH/bin"  &&

  export ADA_OBJECTS_PATH="$LIB_DIR/adalib"  &&
  export ADA_INCLUDE_PATH="$LIB_DIR/adainclude"  &&

  OPTS="--enable-libada $OPTS"

fi  &&

OPTS="$GCJ_HOME $OPTS"                                               &&
OPTS="--prefix=${INSTALL_ROOT}/usr $OPTS"                          &&
OPTS="--libdir=${INSTALL_ROOT}/usr/lib $OPTS"                      &&
OPTS="--libexecdir=${INSTALL_ROOT}/usr/lib $OPTS"                  &&
OPTS="--mandir=${INSTALL_ROOT}/usr/share/man $OPTS"                &&
OPTS="--infodir=${INSTALL_ROOT}/usr/share/info $OPTS"              &&
OPTS="--with-bugurl=http://bugs.sourcemage.org $OPTS"              &&
OPTS="--enable-languages=${GCC_COMPILER// /,},lto $OPTS"     &&
OPTS="--enable-shared $OPTS"                                       &&
OPTS="--enable-threads=posix $OPTS"                                &&
OPTS="--enable-__cxa_atexit $OPTS"                                 &&
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
OPTS="--enable-lto $OPTS"                                          &&
OPTS="--with-linker-hash-style=gnu $OPTS"                          &&
OPTS="--disable-werror $OPTS"                                      &&
OPTS="--enable-checking=release $OPTS"                             &&
OPTS="$GCC_MULTILIB $OPTS"                                         &&

cd $SOURCE_DIRECTORY.bld                                              &&
$SOURCE_DIRECTORY/configure $OPTS                                     &&

make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" $GCC_TARGET
