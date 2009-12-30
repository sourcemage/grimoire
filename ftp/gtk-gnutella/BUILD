if [ "$GNUTELLA_GTK_IP6" == "y" ]; then
  OPTS="-Dd_ipv6='true' ${OPTS}"
else
  OPTS="-Dd_ipv6=undef ${OPTS}"
fi                                          &&

if [ "$GNUTELLA_GTK_FAST_ASSERT" == "y" ]; then
  OPTS="-Dd_fast_assert='yes' ${OPTS}"
else
  OPTS="-Dd_fast_assert=undef ${OPTS}"
fi                                          &&

if [ "$GNUTELLA_GTK_NLS" == "y" ]; then
  OPTS="-Dd_nls='yes' ${OPTS}"
else
  OPTS="-Dd_nls=undef ${OPTS}"
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
 $OPTS                                      &&
make
