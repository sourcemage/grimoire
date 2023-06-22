export CARGO_HOME="${SOURCE_DIRECTORY}/cargo_home" &&

cargo fetch --locked --target "${BUILD/-pc-/-unknown-}" &&
cargo build --locked --release --no-default-features ${OPTS}
