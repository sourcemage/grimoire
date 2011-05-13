OPTS="$OPTS -DCMAKE_BUILD_TYPE=Release" &&
OPTS="$OPTS -DHAVE_AGG=OFF" &&
OPTS="$OPTS -DGNAT_LIB=/usr/lib/gcc/${BUILD}/$(installed_version gcc)/adalib/libgnat.so" &&
OPTS="$OPTS -DHAVE_FREETYPE=OFF" &&
message "${MESSAGE_COLOR}${OPTS}${DEFAULT_COLOR}" &&
qt4_cmake_build
