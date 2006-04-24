(
patch -p0 <$SCRIPT_DIRECTORY/xroottext.patch &&
xmkmf                                        &&
make install                                 &&
mkdir -pv /usr/doc/$SPELL                    &&
cp -v README COPYING TODO /usr/doc/$SPELL    &&
chmod 644 /usr/doc/$SPELL/*
) > $C_FIFO 2>&1
