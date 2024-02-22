sed "
	/^PREFIX *=/ s@=.*@= $INSTALL_ROOT/usr@
" configs/linux.mk > config.mk &&
make all check
