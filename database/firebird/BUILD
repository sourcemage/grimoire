# apply gcc4 patch
bzcat $SPELL_DIRECTORY/*.bz2 | patch -p1 &&
#invoke_gcc                              &&
# at present the build only works for everything in one directory 
# tree /usr/firebird

  local SCRIPT                           &&
  PREFIX=${INSTALL_ROOT}/usr/firebird		&&
  sed -i -e \
"s/-O3 -march=i586 -mcpu=i686//;s/-ggdb//;s/-shared/-shared $LDFLAGS/" \
       -e "s/-fno-builtin//;s/-fno-omit-frame-pointer//"      \
	builds/posix/prefix.linux		&&

# make this compatible with smgl init system
  if [ "$WHICH" == "cvs" ];then
    SCRIPT=builds
  else
    SCRIPT=src
  fi                                            &&
  sed -e "s:rc\.d/::;s:d/f:d/runlevels/\%3/f:" -i \
     $SCRIPT/install/arch-specific/linux/misc/changeDBAPassword.sh.in&&

  OPTS="${OPTS} ${FB_SS}"                       &&

  NOCONFIGURE=1 . ./autogen.sh			&&
  ./configure 				\
	--prefix=$PREFIX 		\
	--with-editline			\
	$OPTS					&&
  make                                          &&
# prepare an install image
  cd gen                                        &&
  ./install/makeInstallImage.sh

