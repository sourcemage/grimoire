patch -p1 < $SCRIPT_DIRECTORY/gcc-3.4.patch            &&
patch -p1 < $SCRIPT_DIRECTORY/mpeg2_api.diff           &&
patch -p1 < $SCRIPT_DIRECTORY/magickfilter_ftbfs.diff  &&
sedit 's/`Magick-config --libs`/`Magick-config --ldflags` `Magick-config --libs`/' configure  &&
export OPTS="$OPTS --without-pic"  &&
default_build
