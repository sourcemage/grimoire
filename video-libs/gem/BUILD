mkdir src/libdv  &&
cp $SCRIPT_DIRECTORY/dv1394.h src/libdv  &&
cd  src/Gnu         &&
sedit  "s:GEMLIBS=.*$:GEMLIBS=../../GemLibs:"  configure  &&
default_build
