unset LDFLAGS &&
unset CFLAGS &&

cd "$SOURCE_DIRECTORY" &&
./configure --prefix=${INSTALL_ROOT}/usr $OPTS &&
make xen tools &&

if [[ $XEN_STUBDOM == y ]]; then
  make_single &&
  make stubdom &&
  make_normal
fi
