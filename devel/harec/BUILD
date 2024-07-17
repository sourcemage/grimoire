sed "
	/^PREFIX *=/ s@=.*@= $INSTALL_ROOT/usr@
	/^CFLAGS *=/ s/=/+=/ # honour env CFLAGS
	s/ -Werror / /
" configs/linux.mk > config.mk &&
make all check
