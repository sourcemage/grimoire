if [ "$CURLCLIENT" == "n" ]; 
then
    MYCONF="--disable-curl-client " &&
    message "${MESSAGE_COLOR}Disabled curl client build${DEFAULT_COLOR}"
fi &&
if [ "$ABYSSERV" == "n" ];
then
    MYCONF="$MYCONF --disable-abyss-server " &&
    message "${MESSAGE_COLOR}Disabled abyss server build${DEFAULT_COLOR}"
fi &&
if [ "$CGISERV" == "n" ];
then
    MYCONF="$MYCONF --disable-cgi-server " &&
    message "${MESSAGE_COLOR}Disabled cgi server build${DEFAULT_COLOR}"
fi &&
if [ "$CPLUSPLUS" == "n" ];
then
    MYCONF="$MYCONF --disable-cplusplus " &&
    message "${MESSAGE_COLOR}Disabled c++ wrapper build${DEFAULT_COLOR}"
fi &&
if [ "$BUNICODE" == "n" ];
then
    MYCONF="$MYCONF --disable-cplusplus " &&
    message "${MESSAGE_COLOR}Disabled unicode support build${DEFAULT_COLOR}"
fi &&
if [ "$ABFORK" == "y" ];
then
    MYCONF="$MYCONF --disable-abyss-threads " &&
    message "${MESSAGE_COLOR}Disabled abys thread support build${DEFAULT_COLOR}"
fi &&

./configure \
    --prefix=${INSTALL_ROOT}/usr                          \
    --bindir=${INSTALL_ROOT}/usr/bin                      \
    --sbindir=${INSTALL_ROOT}/usr/sbin                    \
    --datadir=${INSTALL_ROOT}/usr/share                   \
    --sysconfdir=${INSTALL_ROOT}/etc                      \
    --libdir=${INSTALL_ROOT}/usr/lib                      \
    --includedir=${INSTALL_ROOT}/usr/include              \
    --infodir=${INSTALL_ROOT}/usr/info                    \
    --mandir=${INSTALL_ROOT}/usr/share/man                \
    --libexecdir=${INSTALL_ROOT}/usr/libexec              \
    --datadir=${INSTALL_ROOT}/usr/share                   \
    --localstatedir=${INSTALL_ROOT}/var/lib/xmlrpc-c      \
    --sharedstatedir=${INSTALL_ROOT}/usr/share/xmlrpc-c   \
    $OPTS                                                 \
    $MYCONF                                               &&

make
