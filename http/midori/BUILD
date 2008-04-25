if [ "$MIDORI_VCS" == "y" ]; then
   ./autogen.sh
fi  &&

CPPFLAGS="$CPPFLAGS -I$INSTALL_ROOT/usr/include/WebKit/webkit"

sed -i "s:WebKitGtk:webkit-1.0:g" configure &&

default_build
