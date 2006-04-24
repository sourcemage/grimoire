persistent_add  SOURCE_LIB                           &&
make_single                                          &&
make < $SCRIPT_DIRECTORY/atlas-${VERSION}.config     &&
ARCH=`ls -1 Make.Linux* | sed -e 's/Make.//'`        &&
make  install  arch=$ARCH                            &&
SOURCE_LIB=$SOURCE_DIRECTORY/lib/$ARCH
