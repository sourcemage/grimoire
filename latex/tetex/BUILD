if [ "$CSTEX" = "y" ]; then
    patch -p 0 < $SCRIPT_DIRECTORY/cstetex.patch
fi                                                          &&

OPTS="$OPTS --disable-multiplatform --with-editor=ed"       &&
rm -rf utils/dialog                                         &&
rm -rf utils/texinfo                                        &&
#
# stupid makefile strips binaries it knows about, whether it
# installed them or not!
#
for i in info infokey install-info makeinfo texindex;
do
  sedit  "s/ $i//g" Makefile.in
done                                                        &&
make_single                                                 &&
default_build                                               &&
make_normal
