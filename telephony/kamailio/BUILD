cd "$SOURCE_DIRECTORY" &&
make_single &&
make cfg \
	PREFIX="$INSTALL_ROOT"/usr \
	LIBDIR=lib \
	cfg_target="$INSTALL_ROOT/etc/$SPELL" \
	&&
make &&
make_normal
