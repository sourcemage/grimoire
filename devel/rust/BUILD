export CLANG_INSTALL_DIR=/usr &&
CXXFLAGS="${CXXFLAGS//-DPIC}" &&
if spell_ok $SPELL;then
  OPTS+=" --enable-local-rust --local-rust-root=$INSTALL_ROOT/usr"
fi &&
./configure --prefix="$INSTALL_ROOT"/usr --enable-extended --disable-docs --enable-llvm-link-shared $OPTS &&

sed -i "/BOOTSTRAP.*doc/d" Makefile &&

make
