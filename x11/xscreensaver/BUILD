#sedit  "6690s/Screensaver/Screensaver Properties/"  po/es.po    &&

OPTS="--with-dpms-ext --with-xinerama-ext --with-xf86vmode-ext     \
            --with-xf86gamma-ext --with-proc-interrupts --with-xshm-ext  \
            --with-xdbe-ext --with-readdisplay  --without-motif $OPTS"  &&
if [ "$XSCSV" == "n" ]; then
   OPTS="--without-gtk --without-xml $OPTS"
fi  &&

default_build
