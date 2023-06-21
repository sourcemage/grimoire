if is_depends_enabled $SPELL libgit2; then
  default_build
else
  env CARGO_HOME="$SOURCE_DIRECTORY/.cargo" cargo build --release --no-default-features
fi
