OPTS="--eprefix=$INSTALL_ROOT $OPTS" &&

CFLAGS="$CFLAGS -DPIC -fPIC"    &&
CFLAGS="${CFLAGS//-O[gs0-9]/-O3}" &&
CFLAGS="${CFLAGS//-Ofast/-O3}" &&
CFLAGS="${CFLAGS//-O /-O3 }" &&
CFLAGS+=" -fno-tree-vectorize" &&
if [[ "${SMGL_COMPAT_ARCHS[1]}" == "ia32"
   || "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" ]]; then
  CFLAGS+=" -mstackrealign -DUNALIGNED_OK"
fi &&

sedit  "s/-O/$CFLAGS/"  Makefile                   &&

./configure  --prefix=${TRACK_ROOT}/usr  \
             --shared \
                $OPTS                         &&

make DESTDIR=$INSTALL_ROOT &&
cd $SOURCE_DIRECTORY.static &&
./configure --prefix=${TRACK_ROOT}/usr \
            $OPTS &&

make prefix=${INSTALL_ROOT}/usr
