if [ "$DEBUG_SUP" == y ];
then
    MYCONF="$MYCONF --enable-debug"                              &&
    message "${MESSAGE_COLOR}Debug code enabled${DEFAULT_COLOR}"
fi                                                               &&

./configure                                                      \
    --prefix=${INSTALL_ROOT}/usr                                 \
    --sysconfdir=${INSTALL_ROOT}/etc                             \
    --localstatedir=${INSTALL_ROOT}/var                          \
    $OPTS                                                        \
    $MYCONF                                                      &&
  
make
