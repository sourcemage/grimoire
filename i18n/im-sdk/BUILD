# excluded leif, doesn't build
BUILDDIRS="lib/EIMIL lib/iiimp lib/iiimcf \
  iiimsf iiimxcf/xiiimp.so iiimxcf/htt_xbe iiimgcf"

# this makes it compile with libiconv installed
cp lib/CSConv/iconv/iconv.h include/   &&

pushd lib/CSConv                       &&
./configure \
  --prefix=$INSTALL_ROOT/usr/lib/im \
  --without-libiconv-prefix \
  $OPTS                                &&
make                                   &&
popd                                   &&

for dir in $BUILDDIRS; do
 {
  pushd $dir                             &&
  if [[ ! -e configure ]]; then
    ./autogen.sh
  fi                                     &&
  ./configure \
    --prefix=$INSTALL_ROOT/usr \
    --sysconfdir=$INSTALL_ROOT/etc \
    --localstatedir=$INSTALL_ROOT/var \
    --libdir=$INSTALL_ROOT/usr/lib \
    --without-libiconv-prefix \
    $OPTS                                &&
  if [[ $dir == iiimgcf ]]; then
    # fix broken po files
    sed -i '/Last-Translator/{ s/^.*$/&\n"Language-Team: unknown;\\n"/ }' po/*.po
  fi                                     &&
  make                                   &&
  popd 
 } || return 1
done
