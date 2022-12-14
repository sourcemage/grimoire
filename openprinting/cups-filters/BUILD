OPTS+=" --disable-static" &&
CFLAGS+=" -Wno-deprecated-declarations -Wno-stringop-truncation" &&
OPTS+=" $CPF_OPTS" &&
OPTS+=" --with-rcdir=no --disable-mutool" &&
CPPFLAGS+=" -Wno-deprecated-declarations" &&
# C++17 is required to build against qpdf 11.4.0+
# (not detected as of cups-filters 1.28.17)
CXXFLAGS+=' -std=c++17' &&
default_build
