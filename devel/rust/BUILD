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
#if spell_ok "$SPELL"; then
#  _rust_root="$INSTALL_ROOT/usr"
#else
  _rust_root="$SOURCE_DIRECTORY/stage0-bootstrap" &&
  install -D -m555 -t "$_rust_root"/bin "${SOURCE3%.tar.xz}"/cargo/bin/cargo &&
  for i in "$SOURCE4" "$SOURCE5"; do
    ./"${i%.tar.xz}"/install.sh \
        --destdir="$_rust_root" --prefix=/ --disable-ldconfig || break
  done &&
#fi &&
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
          --disable-docs \
           --enable-llvm-link-shared \
        --llvm-root=$INSTALL_ROOT/usr \
          --disable-codegen-tests \
                    $OPTS &&

ln -sf bootstrap.toml config.toml &&

# various switches to disable static build, downloading and using llvm
# toolchain from rust CI and to set user profile
sed -e "s;profile =.*;profile = 'user';" \
    -e '/^\[llvm\]/adownload-ci-llvm = false' \
    -e '/^\[rust\]/alld = false' \
    -e '/^\[llvm\]/aninja = false' \
    -e '/^\[build\]/aoptimized-compiler-builtins = false' -i config.toml &&

 if list_find "${RUST_TOOLS}" "none"; then
   sed '/^\[build\]/atools = \[\]' -i config.toml
elif list_find "${RUST_TOOLS}" "default"; then
  sed '/^\[build\]/atools = \[ "cargo", "rustdoc" \]' -i config.toml
else
  sed "/^\[build\]/atools = \[ \"${RUST_TOOLS// /\", \"}\" \]" -i config.toml
fi &&

export CARGO_HOME="$SOURCE_DIRECTORY/cargo_home" &&

python3 ./x.py build  --config="${SOURCE_DIRECTORY}/config.toml" \
-j $((${#DISTCC_HOSTS[*]} * JOBS_PER_HOST + MAKE_NJOBS)) &&

# fake install
if spell_ok "${SPELL}"; then
  mkdir -p "${SOURCE_DIRECTORY}/INSTALL_ROOT" &&
  DESTDIR="${SOURCE_DIRECTORY}/INSTALL_ROOT" python3 ./x.py install \
    --config="${SOURCE_DIRECTORY}/config.toml" -j"${MAKE_NJOBS:-1}"
fi
