if is_depends_enabled $SPELL wayland && ! is_depends_enabled $SPELL libx11; then
  env CARGO_HOME="$SOURCE_DIRECTORY/.cargo" cargo build \
    --release --no-default-features --features=wayland
elif is_depends_enabled $SPELL libx11 && ! is_depends_enabled $SPELL wayland; then
  env CARGO_HOME="$SOURCE_DIRECTORY/.cargo" cargo build \
    --release --no-default-features --features=x11
else
  env CARGO_HOME="$SOURCE_DIRECTORY/.cargo" cargo build --release
fi
