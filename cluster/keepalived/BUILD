if [ "$SYNC" == "y"  ]; then
    MYCONF="--disable-syncd " &&
    message "${MESSAGE_COLOR}Disabled lvs syncd${DEFAULT_COLOR}"
fi &&
if [ "$LVS" == "y"  ];
then
    MYCONF="$MYCONF --disable-lvs " &&
    message "${MESSAGE_COLOR}Disable lvs framework ${DEFAULT_COLOR}"
fi &&
if [ "$VRRP" == "y"  ];
then
    MYCONF="$MYCONF --disable-vrrp "
    message "${MESSAGE_COLOR}Not using VRRP ${DEFAULT_COLOR}"
fi &&
if [ "$KDEBUG" == "y"  ];
then
    MYCONF="$MYCONF --enable-debug "
    message "${MESSAGE_COLOR}Enabling debug ${DEFAULT_COLOR}"
fi &&
if [ "$PROF" == "y"  ];
then
    MYCONF="$MYCONF --enable-profile "
    message "${MESSAGE_COLOR}Using profiling ${DEFAULT_COLOR}"
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
    --localstatedir=${INSTALL_ROOT}/var/lib/keepalived    \
    --sharedstatedir=${INSTALL_ROOT}/usr/share/keepalived \
    $OPTS                                                 \
    $MYCONF                                               &&


make 
