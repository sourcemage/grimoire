if [[ $EWW_WAYLAND == y ]]; then
  cargo build --release --no-default-features --features=wayland
else
  cargo build --release --no-default-features --features x11
fi
