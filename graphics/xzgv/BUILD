sedit  "s:PREFIX=/usr/local:PREFIX=${INSTALL_ROOT}/usr:"  config.mk &&
sedit  "s:CFLAGS=.*:CFLAGS=${CFLAGS}:" config.mk                    &&
cd ${SOURCE_DIRECTORY}/src &&
default_build_make         &&
cd ${SOURCE_DIRECTORY}/doc &&
default_build_make
