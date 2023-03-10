export CLANG_INSTALL_DIR=/usr &&
CFLAGS="${CFLAGS//-DPIC}" &&
CXXFLAGS="${CXXFLAGS//-DPIC}" &&

# for libressl >= 3.5.x
CFLAGS+=" -DHAVE_OPAQUE_STRUCTS=1" &&
CXXFLAGS+=" -DHAVE_OPAQUE_STRUCTS=1" &&

export CFLAGS CXXFLAGS &&

# NEVER use the rust in /usr.
# 1. It will be too old in the general case. We'd need to ensure taking
#    each release step.
# 2. It will be broken right now, anyway, as we just updated LLVM and
#    /usr/bin/rustc will be missing its soversion. You cannot win.
#    Maybe we need our own bootstrap packages. Or a chain build starting
#    with the latest available cache.
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
message "${MESSAGE_COLOR}OPTS=$OPTS${DEFAULT_COLOR}" &&
./configure \
            --build="${BUILD/-pc-/-unknown-}" \
           --prefix="$INSTALL_ROOT"/usr \
  --release-channel="stable" \
           --enable-local-rust \
  --local-rust-root="$_rust_root" \
           --enable-locked-deps \
           --enable-vendor \
           --enable-extended \
           --enable-missing-tools \
          --disable-docs \
           --enable-llvm-link-shared \
  --llvm-root=$INSTALL_ROOT/usr --disable-llvm-version-check --disable-codegen-tests \
                    $OPTS &&

# static doesn't work
sed -i '/^#crt-static/acrt-static = false' config.toml &&

sed -i "/BOOTSTRAP.*doc/d" Makefile &&

export CARGO_HOME="$SOURCE_DIRECTORY/cargo_home" &&

default_build_make &&

# fake install
if spell_ok "${SPELL}"; then
  mkdir -p "${SOURCE_DIRECTORY}/INSTALL_ROOT" &&
  make DESTDIR="${SOURCE_DIRECTORY}/INSTALL_ROOT" install
fi
