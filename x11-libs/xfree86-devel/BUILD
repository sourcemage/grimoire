cd config/util                                   &&
make -f Makefile.ini lndir                       &&
cp lndir $SOURCE_DIRECTORY.bld/                  &&
cd $SOURCE_DIRECTORY.bld                         &&
./lndir ../xc/                                   &&

### differnet approach to old bug
### Fix Bug #3486, which stops the build process
ln -sf $SOURCE_DIRECTORY.bld/lib/font/builtins $SOURCE_DIRECTORY.bld/lib/font/builtins/unshared &&

### will this fix the mysterious error ?
mkdir -p $SOURCE_DIRECTORY.bld/exports/include/X11/                                              &&
ln -sf $SOURCE_DIRECTORY/lib/xtrans/Xtrans.h  $SOURCE_DIRECTORY.bld/exports/include/X11/Xtrans.h &&
  
### Copy sis_common.h from the drivers to the GL dri dir
cp -f $SOURCE_DIRECTORY.bld/programs/Xserver/hw/xfree86/drivers/sis/sis_common.h $SOURCE_DIRECTORY.bld/lib/GL/mesa/src/drv/sis/ && 
cp   $SOURCE_DIRECTORY.bld/extras/freetype2/include/ft2build.h  $SOURCE_DIRECTORY.bld/lib/font/FreeType &&
make World
  
### Start compiling where the prior left off

make
