#  Set compile to use STLport's headers before gcc's...
PATH_HOLD=${PATH}                                                &&
export  PATH=${SOURCE_DIRECTORY}/stlport:${PATH}                 &&
sedit  "s:../g++-v3:/usr/include/c++/`installed_version gcc`:g"  \
       stlport/stl/config/_gcc.h                                  &&

cd  build/lib                         &&
cp  gcc.mak  Makefile &&
sedit  's:\-O2:${CFLAGS}:'  Makefile  &&
make_single                           &&
make  clean  depend  install
