create_account gdm                                                      &&

if    spell_ok  linux-pam;  then  SCHEME="pam"
elif  spell_ok  shadow;     then  SCHEME="shadow"
else  SCHEME="auto"
fi                                                                      &&

OPTS="$OPTS --enable-authentication-scheme=$SCHEME"                     &&

if [ "$XDMCP" == "y" ]; then
   OPTS="$OPTS --with-xdmcp=yes"
else
   OPTS="$OPTS --with-xdmcp=no"
fi                                                                      &&

if [ "$SELINUX" == "y" ]; then
   OPTS="$OPTS --with-selinux"
fi                                                                      &&

if [ "$IPV6" == "y" ]; then
   OPTS="$OPTS --enable-ipv6=yes"
else
   OPTS="$OPTS --enable-ipv6=no"
fi                                                                      &&

if [ "$DBUSLAUNCH" == "y" ]; then
   patch -p0 < $SCRIPT_DIRECTORY/Xsession-dbus.patch
fi                                                                      &&

LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"                                     &&

./configure   --build=$BUILD                                            \
              --prefix=${INSTALL_ROOT}/usr                              \
              --sysconfdir=${INSTALL_ROOT}/etc                          \
              --localstatedir=${INSTALL_ROOT}/var                       \
	      --mandir=${INSTALL_ROOT}/usr/share/man			\
              $OPTS                                                     &&

sedit 's#$(LINK)#$(LINK) $(LIBS)#' daemon/Makefile                      &&
make

