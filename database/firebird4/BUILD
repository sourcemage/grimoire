CXXFLAGS+=" -Wno-deprecated" &&
CXXFLAGS+=" -Wno-stringop-overflow" &&
CXXFLAGS+=" -fPIC" &&
persistent_add FB_PREFIX               &&
export FB_PREFIX=${INSTALL_ROOT}/opt/firebird4 &&
OPTS+=' --with-fblog=/var/log' &&
cd $SOURCE_DIRECTORY &&
./configure --prefix=$FB_PREFIX $OPTS &&
make -j6
