export CLANG_INSTALL_DIR=/usr &&
CFLAGS="${CFLAGS//-DPIC}" &&
CXXFLAGS="${CXXFLAGS//-DPIC}" &&
if spell_ok "$SPELL"; then
  _rust_root="$INSTALL_ROOT/usr"
else
  _rust_root="$SOURCE_DIRECTORY/stage0-bootstrap" &&
  install -D -m555 -t "$_rust_root"/bin "${SOURCE3%.tar.xz}"/cargo/bin/cargo &&
  for i in "$SOURCE4" "$SOURCE5"; do
    ./"${i%.tar.xz}"/install.sh \
        --destdir="$_rust_root" --prefix=/ --disable-ldconfig || break
  done
fi &&
./configure \
	--build="${BUILD/-pc-/-unknown-}" \
	--prefix="$INSTALL_ROOT"/usr \
	--enable-local-rust \
	--local-rust-root="$_rust_root" \
	--enable-locked-deps \
	--enable-vendor \
	--enable-extended \
	--disable-docs \
	--enable-llvm-link-shared \
	$OPTS &&

# static doesn't work
sed -i '/^#crt-static *= *false/s/#//' config.toml &&

sed -i "/BOOTSTRAP.*doc/d" Makefile &&

export CARGO_HOME="$SOURCE_DIRECTORY/cargo_home" &&

default_build_make
