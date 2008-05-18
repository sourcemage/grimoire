#sedit  "6690s/Screensaver/Screensaver Properties/"  po/es.po    &&

OPTS="--with-dpms-ext $OPTS"
OPTS="--with-xinerama-ext $OPTS"
OPTS="--with-xf86vmode-ext $OPTS"
OPTS="--with-xf86gamma-ext $OPTS"
OPTS="--with-randr-ext $OPTS"
OPTS="--with-proc-interrupts $OPTS"
OPTS="--with-xshm-ext $OPTS"
OPTS="--with-xdbe-ext $OPTS"
OPTS="--with-readdisplay $OPTS"
OPTS="--enable-locking $OPTS"
OPTS="--without-motif $OPTS"
if [ "$XSCSV" == "n" ]; then
   OPTS="--without-gtk --without-xml $OPTS"
fi  &&

default_build
