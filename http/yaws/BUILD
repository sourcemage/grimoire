(
	./configure	--build=$BUILD                  \
			--prefix=/usr                   \
			--sysconfdir=/etc               \
			--localstatedir=/var            \
			$OPTS                           &&
	make all					&&
	cd applications/wiki				&&
	make all					&&
	cd ../mail					&&
	make all					&&
	cd ../..					&&
	prepare_install					&&
	make install
	cd applications/wiki
	make install
	cd ../mail
	make install
	cd ../..
) >$C_FIFO 2>&1
