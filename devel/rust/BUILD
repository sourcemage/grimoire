export CLANG_INSTALL_DIR=/usr &&
CXXFLAGS="${CXXFLAGS//-DPIC}" &&
if spell_ok $SPELL;then
  OPTS+=" --local-rust-root==$INSTALL_ROOT/usr"
fi &&
./configure --prefix="$INSTALL_ROOT"/usr --disable-docs --enable-llvm-link-shared $OPTS &&
make
