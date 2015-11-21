OPTS="--without-libgif $OPTS" &&
if  spell_ok  xorg;  then
  CFLAGS="${CFLAGS} -I${INSTALL_ROOT}/usr/X11R6/include"
fi  &&

CFLAGS=${CFLAGS/-O3/-O2}        &&
OPTS="${OPTS} --disable-glitz"  && 
default_build
