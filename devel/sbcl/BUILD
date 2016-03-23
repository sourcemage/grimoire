xc_prefix="$INSTALL_ROOT"/usr/bin &&

if ! spell_ok sbcl; then
  bindir="$BUILD_DIRECTORY/$SPELL-$BIN_VERSION-$SBCL_ARCH-linux" &&
  xc_prefix="$bindir/src/runtime" &&
  export SBCL_HOME="$bindir/output"
fi &&

sh make.sh \
  --prefix="$INSTALL_ROOT"/usr \
  --xc-host="$xc_prefix"/sbcl
