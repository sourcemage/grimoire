export LCL_PLATFORM=$LAZ_GUI          &&
if [ $LAZ_GUI == qt4 ];then
  cd lcl/interfaces/qt                &&
  CFLAGS="-I/usr/include/qt4 $CFLAGS" &&
  cd $SOURCE_DIRECTORY 
fi                                    &&
make                                  &&
strip -s lazarus startlazarus
