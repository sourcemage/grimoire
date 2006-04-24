if [[ "${HOST%%-*}" == x86_64 ]]; then
  CFLAGS="${CFLAGS//-[fD]PIC/}"
fi &&

make_single    &&
default_build  &&
make_normal
