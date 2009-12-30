create_account gdm                                    &&

if    spell_ok  linux-pam;  then  SCHEME="pam"
elif  spell_ok  shadow;     then  SCHEME="shadow"
else  SCHEME="auto"
fi                                                    &&

OPTS="$OPTS --enable-authentication-scheme=$SCHEME"   &&
OPTS="${OPTS} ${GDM_SECURE} ${GDM_IPV6}"              &&

if [ "$DBUSLAUNCH" == "y" ]; then
   patch -p0 < $SCRIPT_DIRECTORY/Xsession-dbus.patch
fi                                                    &&

LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"                   &&

./configure   --build=$BUILD                          \
              --prefix=${INSTALL_ROOT}/usr            \
              --sysconfdir=${INSTALL_ROOT}/etc        \
              --localstatedir=${INSTALL_ROOT}/var     \
              --mandir=${INSTALL_ROOT}/usr/share/man  \
              $OPTS                                   &&

sedit 's#$(LINK)#$(LINK) $(LIBS)#' daemon/Makefile    &&
make

