cat <<-EOF >user.make &&
	libmujs=libmujs.so
	prefix="$INSTALL_ROOT"/usr
EOF
make -j "$MAKE_NJOBS" CC="$CC" $OPTS
