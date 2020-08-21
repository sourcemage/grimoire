if ! is_version_less $(installed_version binutils) 2.35; then
  LDFLAGS+=" -Wl,--allow-multiple-definition"
fi &&

# Flags to allow building against lua 5.3
#CFLAGS+=" -DLUA_COMPAT_APIINTCASTS"

# LuaTeX needs this
CXXFLAGS+=" -fpermissive" &&

# hide warnings about unable to find it's own config files
export KPATHSEA_WARNING=0 &&
# X seems to be only there for xdvi which we use external
cd "$COMPILE_DIRECTORY" &&
"$SOURCE_DIRECTORY"/configure --prefix="$INSTALL_ROOT"/usr \
                            --sysconfdir="$INSTALL_ROOT"/etc \
                            --localstatedir="$INSTALL_ROOT"/var \
                            --mandir="$INSTALL_ROOT"/usr/share/man \
                            --infodir="$INSTALL_ROOT"/usr/share/info \
                            --datadir="$INSTALL_ROOT"/usr/share \
                            --enable-pdftex \
                            --disable-xindy \
                            --disable-etex \
                            --disable-aleph \
                            --disable-multiplatform \
                            --without-x \
                            --disable-native-texlive-build \
                            --disable-bundled-libs \
                            --disable-static --enable-shared \
                            --with-banner-add="/Source Mage GNU/Linux" \
                            $OPTS &&
make
