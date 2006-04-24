patch -p0 < $SCRIPT_DIRECTORY/build-ooo.diff &&

OPTS="$OPTS --enable-gtk --with-system-gcc --with-icons=gnome --with-widgetset=gtk --with-tag=OOO_1_1_2" &&

CONFIGURE_OPTIONS="--with-lang=ALL \
--enable-libart --enable-libsn --enable-crashdump=no \
--enable-symbols=no --enable-fontconfig --with-system-zlib \
--with-system-freetype  --with-system-db --with-db-version=4.2 \
--without-fonts --enable-gtk --disable-mozilla \
--with-system-sane-headers --with-system-x11-extensions-headers \
--with-system-unixodbc-headers --with-system-curl \
--with-python=/usr/bin/python --with-system-xrender --disable-rpath" &&

export CONFIGURE_OPTIONS                                &&

if [ "$DEVEL" == "y" ]; then
   OPTS="$OPTS --enable-devel"
fi                                        &&

make_single    &&
default_build  &&
make_normal
