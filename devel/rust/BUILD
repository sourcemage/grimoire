CXXFLAGS="${CXXFLAGS//-DPIC}" &&
if spell_ok $SPELL;then
  OPTS+=" --local-rust-root==$INSTALL_ROOT/usr"
fi &&
./configure --prefix="$INSTALL_ROOT"/usr --disable-docs $OPTS &&
make
