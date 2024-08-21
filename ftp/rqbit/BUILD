export CARGO_HOME="${SOURCE_DIRECTORY}/cargo_home" &&

cargo fetch --locked --target "${BUILD/-pc-/-unknown-}" &&
RUSTUP_TOOLCHAIN=stable cargo build --release --frozen
