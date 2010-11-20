cd ${SOURCE_DIRECTORY}/gnat &&
gnatmake xsnamest.adb       &&
./xsnamest                  &&
mv snames.ns snames.ads     &&
mv snames.nb snames.adb     &&
cd ${SOURCE_DIRECTORY}      &&
make all prefix=${INSTALL_ROOT}/usr
