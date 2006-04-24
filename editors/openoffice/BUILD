if [ "$OPENOFFICE_VERSION" == "stable" ]; then
invoke_gcc
optimize
fi


### configure
	cd $SOURCE_DIRECTORY/config_office/               &&
	export CXXFLAGS="${CXXFLAGS} -I/usr/X11R6/include -I/usr/include/nspr -I/usr/include/nss"       &&
export CFLAGS="${CFLAGS} -I/usr/include/nspr -I/usr/include/nss" &&
if [ "$OPENOFFICE_VERSION" == "stable" ]; then
optimize
fi
if [ "$OPENOFFICE_EPM" == "internal" ]; then
OPTS="${OPTS} --enable-epm --with-epm=internal"
fi
if [ "$OPENOFFICE_EPM" == "none" ]; then
OPTS="${OPTS} --disable-epm"
fi
if [ "$OPENOFFICE_VERSION" == "devel" ]; then
OPTS="${OPTS} --with-build-version=Built_by_Source_Mage"
fi
echo OPTS=$OPTS &&
	./configure                                       \
		--with-lang=${LANGUAGE}                   \
		--with-dict=${DICTIONARY}                  \
		--prefix=${INSTALL_ROOT}/usr              \
		--sysconfdir=${INSTALL_ROOT}/etc          \
		--localstatedir=${INSTALL_ROOT}/var       \
                --mandir=${INSTALL_ROOT}/usr/share/man    \
                --infodir=${INSTALL_ROOT}/usr/share/info  \
                --disable-mozilla                         \
		$OPENOFFICE_OPTS $OPTS                    &&

	cd $SOURCE_DIRECTORY &&
  ./bootstrap                                                                       &&
  tcsh -c "source LinuxIntelEnv.Set && \
           env && \
           dmake" &&
if [ "$OPENOFFICE_VERSION" == "stable" ]; then
  cd $SOURCE_DIRECTORY/instsetoo/unxlngi4.pro/01/normal	                            &&
  sedit "s:oo_home=OpenOffice.org${VERSION}:oo_home=openoffice:" install                 &&
  chmod +x install
else
echo "build done"
fi