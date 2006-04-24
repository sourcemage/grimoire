if    [  -f  $CONFIG_CACHE/host.def  ];  then
  cp     $CONFIG_CACHE/host.def  config/cf/host.def
fi                                                      &&
### but if it can't be copied then use system defaults for these
if ! grep -q HasFreetype2 config/cf/host.def;  then
  echo "#define HasFreetype2   YES" >> config/cf/host.def
fi                                                      &&
if ! grep -q BuildFreetype2Library  config/cf/host.def;  then
  echo "#define BuildFreetype2Library     NO" >> config/cf/host.def
fi                                                      &&
if ! grep -q HasZlib config/cf/host.def;  then
  echo "#define HasZlib   YES" >> config/cf/host.def
fi                                                      &&
if ! grep -q HasFontconfig config/cf/host.def;  then
  echo "#define HasFontconfig  YES" >> config/cf/host.def
fi                                                      &&
if ! grep -q HasExpat config/cf/host.def;  then
  echo "#define HasExpat  YES" >> config/cf/host.def
fi                                                      &&

message  "${MESSAGE_COLOR}Building XFree86 takes a very long time${DEFAULT_COLOR}"  &&

### removing -Os from copied host.def bug#3694 and cleaning up $CFLAGS
if [ -f config/cf/host.def ];  then
  sedit s"/-Os//g" config/cf/host.def 
fi                                               &&
if  (echo $CFLAGS | grep -q -- "-Os"); then
  export CFLAGS="-O2 ${CFLAGS//-Os/}"
fi                                               &&

if  spell_ok  linux-pam;  then
  echo  "#define  HasPam  YES"  >>  config/cf/site.def
fi                                               &&
### xfree86.org recommends building in a shadow tree 
cd config/util                                   &&
make -f Makefile.ini lndir                       &&
cp lndir $SOURCE_DIRECTORY.bld/                  &&
cd $SOURCE_DIRECTORY.bld                         &&
./lndir ../xc/                                   &&
### differnet approach to old bug
### Fix Bug #3486, which stops the build process if builtinfonts is selected
ln -sf $SOURCE_DIRECTORY.bld/lib/font/builtins $SOURCE_DIRECTORY.bld/lib/font/builtins/unshared &&

make  World
