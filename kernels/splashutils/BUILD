#
# Make libpng and tiff optional
#


if  [ "$SPLASHUTILS_PNG"  ==  "n"  ];  then
  sedit  's:.*CONFIG_PNG::g'  config.h
fi  &&

if  [ "$SPLASHUTILS_TTF"  ==  "n"  ];  then
  sedit  's:.*CONFIG_TTF.*::g'  config.h
fi  &&

#
# install_rootify
#
sedit  "s:/etc:$TRACK_ROOT/etc:"  config.h  &&
sedit  "s:/lib:$TRACK_ROOT/lib:"  config.h  &&

#
# Needs the linux source to build against.
# Uses get_kernel_version from $GRIMOIRE/FUNCTIONS
#
ln  -s  $TRACK_ROOT/usr/src/linux-$(get_kernel_version)  linux  &&

#
# Make sure it builds against our system libs
# Currently doesn't work. :(
#
#rm  -rf  libs/{freetype*,jpeg*,libpng*,zlib*}  &&

#
# Now we can build
#
make_single  &&
make         &&
make_normal
