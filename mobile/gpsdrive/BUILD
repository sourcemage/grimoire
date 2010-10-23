#option(WITH_SPEECH "Build with support of speech output" ON)
# we need to disable to compile
#option(LIBGPS_OLD "Build with old libgps version (<2.90)" ON)
# we have newer version in grimire
#option(WITH_MAPNIK "Build with mapnik support" ON)
# for now we don't have the spell yet (http://mapnik.org/)
GPSDRIVE_OPTS="-DWITH_SPEECH=OFF -DLIBGPS_OLD=OFF -DWITH_MAPNIK=OFF $GPSDRIVE_OPTS" &&
prepare_opts &&
cmake_build

