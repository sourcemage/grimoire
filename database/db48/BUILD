# this is needed to make db using stuff work on nptl glibc, do _not_ remove it!
if glibc_is_nptl; then
  LDFLAGS="$LDFLAGS -lpthread"
fi &&

cd  build_unix &&

../dist/configure \
	--prefix=$INSTALL_ROOT/opt/db48  \
	--build=$BUILD                   \
	--disable-java                   \
	--disable-tcl                    \
	--disable-test                   \
	$OPTS                            &&
echo 'install_utilities install_docs:; true' >> Makefile &&
make
