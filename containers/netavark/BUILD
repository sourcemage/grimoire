export CARGO_HOME="$SOURCE_DIRECTORY/cargo_home" &&

cargo fetch --locked --target "$(rustc -vV | sed -n 's/^host: //p')" &&
cargo build --frozen --release &&

if is_depends_enabled $SPELL go-md2man; then
  make -C docs
fi
