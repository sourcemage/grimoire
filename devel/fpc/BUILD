if ! spell_ok fpc;then
  make  all  PP=$SOURCE_DIRECTORY/bootstrap/lib/fpc/2.0.0/ppc386 \
             DATA2INC=$SOURCE_DIRECTORY/bootstrap/bin/data2inc
else
  make all 
fi
# optionally install source files, for use with Lazarus
if [ $FPC_SRC == "y" ];then

  mv packages/extra/gtk2/units/i386-linux/* rtl/units/i386-linux  &&
  mv packages/extra/x11/units/i386-linux/* rtl/units/i386-linux
fi
