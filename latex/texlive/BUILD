# hide warnings about unable to find it's own config files
export KPATHSEA_WARNING=0    &&
# X seems to be only there for xdvi which we use external
export CFLAGS="-I/usr/include/freetype2 $CFLAGS" &&
export CXXFLAGS="-I/usr/include/freetype2 $CXXFLAGS" &&
cd ${COMPILE_DIRECTORY} &&
LIBS="-lpng" $SOURCE_DIRECTORY/configure --prefix=${INSTALL_ROOT}/usr \
                            --sysconfdir=${INSTALL_ROOT}/etc \
                            --localstatedir=${INSTALL_ROOT}/var \
                            --mandir=${INSTALL_ROOT}/usr/share/man \
                            --infodir=${INSTALL_ROOT}/usr/share/info \
                            --datadir=${INSTALL_ROOT}/usr/share \
                            --with-pdftex \
                            --with-tetex \
                            --with-pdfetex \
                            --disable-xindy \
                            --disable-etex \
                            --disable-omega \
                            --disable-aleph \
                            --disable-luatex \
                            --without-graphite \
                            --disable-multiplatform \
                            --without-x \
                            --disable-native-texlive-build \
                            --with-banner-add="/Source Mage GNU/Linux" \
                            $OPTS &&
make_single &&
make &&
make_normal 
#make -C ${SOURCE_DIRECTORY}/texk/kpathsea
