if [ "$GNUTELLA_GTK_IP6" == "y" ]; then
  OPTS="-D ipv6='true' ${OPTS}"
else
  OPTS="-D ipv6='false' ${OPTS}"
fi                                          &&

if [ "$GNUTELLA_GTK_RMTCTRL" == "y" ]; then
  OPTS="-D remotectrl='true' ${OPTS}"
else
  OPTS="-D remotectrl='false' ${OPTS}"
fi                                          &&

./Configure -d -e -r -s -O                  \
 -Dprefix=${INSTALL_ROOT}/usr               \
 -Dsysconfdir=${INSTALL_ROOT}/etc           \
 -Dlocalstatedir=${INSTALL_ROOT}/var        \
 -Dcc=/usr/bin/gcc                          \
 -Dd_nls=undef                              \
 $OPTS                                      &&
make
