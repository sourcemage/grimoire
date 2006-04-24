  patch -Np1 < ${SCRIPT_DIRECTORY}/lesstif-0.94.4-is-ok.patch
  cd   ${SOURCE_DIRECTORY}/makefiles                                                        &&
  cp   Makefile.linux  Makefile.linux.orig                                                  &&
  sed  "s/CFLAGS\=/CFLAGS:=-DBUILD_UNTESTED_NEDIT -DREPLACE_SCOPE /"  Makefile.linux.orig | \
  sed  "s/-DUSE_LPR_PRINT_CMD/& \$\(CFLAGS\)/"  |                                           \
  sed  's/\(LIBS=.*\)/\1 -lXft/' >                                                          \
       Makefile.linux                                                                       &&
  cd   ${SOURCE_DIRECTORY}                                                                  &&
  make linux