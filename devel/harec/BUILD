sed "
	/^PREFIX *=/ s@=.*@= $INSTALL_ROOT/usr@
	/^CFLAGS *=/ s/=/+=/ # honour env CFLAGS
" configs/linux.mk > config.mk &&
make all check
