cp $SCRIPT_DIRECTORY/Makefil* . &&
if  !  grep  -q  "ASM=y"  $SPELL_CONFIG; then
    mv Makefile_plain_C Makefile
fi &&

make clean &&
make