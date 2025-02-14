export CARGO_HOME="${SOURCE_DIRECTORY}/cargo_home" &&

cargo fetch --locked --target "${BUILD/-pc-/-unknown-}" &&

cd "${SOURCE_DIRECTORY}/cargo_home/registry/src/index.crates.io-6f17d22bba15001f" &&
apply_patch_dir "patches" &&
cd "${SOURCE_DIRECTORY}" &&

RUSTUP_TOOLCHAIN=stable cargo build --release --frozen
