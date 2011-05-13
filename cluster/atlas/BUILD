cd  $SOURCE_DIRECTORY/bld                            &&
if is_depends_enabled $SPELL lapack; then
  OPTS="--with-netlib-lapack=$INSTALL_ROOT/usr/lib/liblapack.a $OPTS"
fi                                                   &&

../configure -Si cputhrchk 0 \
             -Fa alg -fPIC \
             -b ${SMGL_COMPAT_ARCHS[0]} \
             --prefix=$INSTALL_ROOT/usr  ${OPTS}     &&
sedit '/RANLIB/s/echo/ranlib/' Make.inc              &&

make_single &&
make                                                 &&
if [ $SHARED_LIB == y ]; then
  cd lib                                             &&
  make shared                                        &&
  cd ..
fi                                                   &&
if [ $PTSHARED_LIB == y ]; then
  cd lib                                             &&
  make ptshared                                      &&
  cd ..
fi &&
make_normal
