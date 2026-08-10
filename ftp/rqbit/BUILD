export CARGO_HOME="${SOURCE_DIRECTORY}/cargo_home" &&

cargo fetch --locked --target "${BUILD/-pc-/-unknown-}" &&

apply_patch_dir -C "${SOURCE_DIRECTORY}/cargo_home/registry/src/index.crates.io-1949cf8c6b5b557f" \
                   "patches" &&

RUSTUP_TOOLCHAIN=stable cargo build --release --frozen
