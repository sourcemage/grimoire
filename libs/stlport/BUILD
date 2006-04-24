#  Set compile to use STLport's headers before gcc's...
PATH_HOLD=${PATH}                                                &&
export  PATH=${SOURCE_DIRECTORY}/stlport:${PATH}                 &&
sedit  "s:../g++-v3:/usr/include/c++/`installed_version gcc`:g"  \
       stlport/config/stl_gcc.h                                  &&
sedit  "s:/usr/local:/usr:"  src/initial_mak/common_macros.mak   &&

cd  build/lib                         &&
cp  gcc.mak  Makefile                 &&
sedit  's:\-O2:${CFLAGS}:'  Makefile  &&
make_single                           &&
make  clean  depend  install
