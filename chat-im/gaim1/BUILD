### had to cook up some pkg-config files for nss and nspr 
CFLAGS="$CFLAGS -I/usr/X11R6/include"
export PKG_CONFIG_PATH='/usr/include/nss:/usr/include/nspr' &&
make_single &&
default_build &&
cd $SOURCE_DIRECTORY                            
