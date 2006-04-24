create_account gdm                                                      &&

if    spell_ok  linux-pam;  then  SCHEME="pam"
elif  spell_ok  shadow;     then  SCHEME="shadow"
else  SCHEME="auto"
fi                                                                      &&

OPTS="$OPTS --enable-authentication-scheme=$SCHEME"                     &&

LDFLAGS="$LDFLAGS -L/usr/X11R6/lib"                                     &&

patch  -p0  <  $SCRIPT_DIRECTORY/dont-install-broken-pam-config.patch   &&

./configure   --build=$BUILD                                            \
              --prefix=${INSTALL_ROOT}/usr                              \
              --sysconfdir=${INSTALL_ROOT}/etc                          \
              --localstatedir=${INSTALL_ROOT}/var                       \
              $OPTS                                                     &&

sedit 's#$(LINK)#$(LINK) $(LIBS)#' daemon/Makefile                      &&
make

