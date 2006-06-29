cd config/util                                   &&
make -f Makefile.ini lndir                       &&
cp lndir $SOURCE_DIRECTORY.bld/                  &&
cd $SOURCE_DIRECTORY.bld                         &&
./lndir ../xc/                                   &&
### differnet approach to old bug
### Fix Bug #3486, which stops the build process if builtinfonts is selected
ln -sf $SOURCE_DIRECTORY.bld/lib/font/builtins $SOURCE_DIRECTORY.bld/lib/font/builtins/unshared &&

make World
  
### will this fix the mysterious error ?
ln -sf $SOURCE_DIRECTORY/lib/xtrans/Xtrans.h  $SOURCE_DIRECTORY.bld/exports/include/X11/Xtrans.h &&
### Start compiling where the prior left off
make
