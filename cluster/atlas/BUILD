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
cd lib                                               &&
if [ $PT_LIB == y ]; then
  make ptshared
else
  make shared
fi                                                   &&
cd ..                                                &&
make check                                           &&
if [ $PT_LIB == y ]; then
  make ptcheck
fi                                                   &&
make time                                            &&
make_normal
