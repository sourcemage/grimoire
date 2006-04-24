# gcc 3.4 fix
local name  &&
for name in elfutils/*/Makefile.in; do
  sedit  's/-Werror//' $name
done  &&
export LDFLAGS=${LDFLAGS/-z combreloc/} &&
export CPPFLAGS="$CPPFLAGS -I/usr/include/python$(installed_version python| cut -c 1-3)" &&
./configure --prefix=${INSTALL_ROOT}/usr &&
make_single  &&
make         &&
make_normal
