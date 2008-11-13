OPTS="$OPTS --enable-gpl --disable-debug $MLT_KDEN $MLT_KINO $MLT_SCALE"  &&        
local XLIB &&
XLIB=$INSTALL_ROOT/usr/X11R6/lib  &&
if [ -d $XLIB ];then
  LDFLAGS="$LDFLAGS -L$XLIB"
fi  &&
default_build
