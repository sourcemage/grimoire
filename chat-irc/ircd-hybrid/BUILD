# $Id$
# man page isn't installed correctly - fix that:
        sedit  "s/\/man8/\/man\/man8/" doc/Makefile.in

	./configure              \
		--build=$BUILD       \
		--prefix=/usr        \
		--sysconfdir=/etc    \
		--localstatedir=/var \
		--enable-rtsigio     \
		--disable-assert     \
		$OPTS                &&
	make
