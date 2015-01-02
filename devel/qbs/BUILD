if is_depends_enabled $SPELL qtbase;then
 QTDIR=$QT5DIR
else
 QTDIR=$QT4DIR
fi
export PKG_CONFIG_PATH="$QTDIR/lib/pkgconfig"
PATH="$QTDIR/bin:$PATH:$SOURCE_DIRECTORY"
qmake -r PREFIX=$QTDIR $OPTS qbs.pro &&
make

