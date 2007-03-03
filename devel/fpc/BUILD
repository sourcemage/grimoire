make_single        &&
if ! spell_ok fpc;then
  make  all  PP=$SOURCE_DIRECTORY/bootstrap/lib/fpc/2.0.0/ppc386 \
             DATA2INC=$SOURCE_DIRECTORY/bootstrap/bin/data2inc
else
  make all
fi &&
make_normal
