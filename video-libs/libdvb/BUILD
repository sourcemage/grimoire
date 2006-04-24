export  CFLAGS="${CFLAGS} -Wall -g"             &&
export  CXXFLAGS=${CFLAGS}                      &&
patch -p0 < ${SCRIPT_DIRECTORY}/config.patch    &&
patch -p0 < ${SCRIPT_DIRECTORY}/makefile.patch  &&
make_single                                     &&
make                                            &&
make_normal
