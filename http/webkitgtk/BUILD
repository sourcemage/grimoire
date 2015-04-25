OPTS="--enable-webkit1 --disable-webkit2 $WEBKIT_OPTS $OPTS" &&
cd ${SOURCE_DIRECTORY}/Source/WebCore/platform &&
sed -i '30i#include <unicode/utf8.h>' text/TextCodecUTF8.h &&
cd graphics/gstreamer &&
sed -i 's/GMutexLocker /WebCore::&/' \
    VideoSinkGStreamer.cpp WebKitWebSourceGStreamer.cpp &&
cd ${SOURCE_DIRECTORY} &&
patch -p0 < $SCRIPT_DIRECTORY/webkitgtk-2.4.8-gcc5.patch &&
default_build
