#  Set compile to use STLport's headers before gcc's...

persistent_add PATH_HOLD              &&
PATH_HOLD=${PATH}                     &&
persistent_add PATH=${SOURCE_DIRECTORY}/stlport:${PATH} &&
sedit  "s:../g++-v3:/usr/include/c++/`installed_version gcc`:g"  \
       stlport/stl/config/_gcc.h      &&

cd  build/lib                         &&
cp  gcc.mak  Makefile &&
sedit  's:\-O2:${CFLAGS}:'  Makefile  &&
make_single                           &&
make  clean  depend  install          &&
make_normal
