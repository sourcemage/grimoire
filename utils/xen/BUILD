unset LDFLAGS &&
unset CFLAGS &&

cd "$SOURCE_DIRECTORY" &&
make xen tools &&

if [[ $XEN_STUBDOM == y ]]; then
  make_single &&
  make stubdom &&
  make_normal
fi
