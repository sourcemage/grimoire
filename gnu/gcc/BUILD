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
sedit "s/lib64/lib/" gcc/config/i386/t-linux64           

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

  if [[  "${SMGL_COMPAT_ARCHS[1]}" == "ia32" ]]; then
    export CC="$SOURCE_DIRECTORY/$ADA_PATH/usr/bin/gnatgcc"
  elif [[  "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" ]]; then
    export CC="$SOURCE_DIRECTORY/$ADA_PATH/usr/bin/gcc"
  fi &&
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

OPTS="--without-ppl --without-cloog $OPTS" &&

cd $SOURCE_DIRECTORY.bld                                              &&
$SOURCE_DIRECTORY/configure                                           \
             --prefix=${INSTALL_ROOT}/usr                             \
             --infodir=${INSTALL_ROOT}/usr/share/info                 \
             --mandir=${INSTALL_ROOT}/usr/share/man                   \
             --enable-threads=posix                                   \
             --enable-languages=$(echo ${GCC_COMPILER} | tr " " ",")  \
             --with-bugurl=http://bugs.sourcemage.org                 \
             --enable-bootstrap                                       \
             --enable-checking=release                                \
             $GCC_MULTILIB $OPTS                                      &&

if [[ "$GCC_TARGET" == "profiledbootstrap" ]] ||
   [[ "$GCC_TARGET" == "profiledbootstrap-lean" ]] ; then
  make_single 
fi  &&
echo "$MAKE_NJOBS  $JOBS_PER_HOST" &&
make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" $GCC_TARGET &&
make_normal
