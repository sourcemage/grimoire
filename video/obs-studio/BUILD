# XXX Fix version number
OPTS+=" -DOBS_VERSION_OVERRIDE=$VERSION" &&
OPTS+=' -DOBS_COMPILE_DEPRECATION_AS_WARNING=ON \
        -DENABLE_NEW_MPEGTS_OUTPUT=OFF \
        -DENABLE_BROWSER=OFF \
        -DENABLE_NVENC=OFF \
        -DENABLE_WEBSOCKET=NO \
        -DENABLE_VST=ON \
        -DENABLE_AJA=OFF' &&

if ! is_depends_enabled $SPELL python3 && ! is_depends_enabled $SPELL luajit; then
  OPTS="-DENABLE_SCRIPTING=OFF $OPTS"
fi &&

default_build
