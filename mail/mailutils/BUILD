if [ "$PAM" == "y"  ]; 
then
    MYCONF="--enable-pam "                                           &&
    message "${MESSAGE_COLOR}Using linux-pam${DEFAULT_COLOR}"
fi                                                                       &&
if [ "$VDOM" == "y"  ];
then
    MYCONF="$MYCONF --enable-virtual-domains "                       &&
    message "${MESSAGE_COLOR}Using Virtual Domains ${DEFAULT_COLOR}"
fi                                                                       &&
if [ "$IMAP" == "y"  ];
then
    MYCONF="$MYCONF --enable-imap"
    message "${MESSAGE_COLOR}Using IMAP ${DEFAULT_COLOR}"
fi                                                                       &&
if [ "$POP" == "y"  ];
then
    MYCONF="$MYCONF --enable-pop"
    message "${MESSAGE_COLOR}Using POP ${DEFAULT_COLOR}"
fi                                                                       &&
if [ "$SMTP" == "y"  ];
then
    MYCONF="$MYCONF --enable-smtp"
    message "${MESSAGE_COLOR}Using SMTP ${DEFAULT_COLOR}"
fi                                                                       &&
if [ "$SENDMAIL" == "y"  ];
then
    MYCONF="$MYCONF --enable-sendmail"
    message "${MESSAGE_COLOR}Using SENDMAIL ${DEFAULT_COLOR}"
fi                                                                       &&
if [ "$MAILDIR" == "y"  ];
then
    MYCONF="$MYCONF --enable-maildir"
    message "${MESSAGE_COLOR}Using MAILDIR ${DEFAULT_COLOR}"
fi                                                                       &&


./configure \
    --bindir=${INSTALL_ROOT}/usr/bin                                     \
    --sbindir=${INSTALL_ROOT}/usr/sbin                                   \
    --datadir=${INSTALL_ROOT}/usr/share                                  \
    --sysconfdir=${INSTALL_ROOT}/etc/mailutils                           \
    --includedir=${INSTALL_ROOT}/usr/include                             \
    --infodir=${INSTALL_ROOT}/usr/info                                   \
    --mandir=${INSTALL_ROOT}/usr/share/man                               \
    --libdir=${INSTALL_ROOT}/usr/lib                                     \
    $OPTS                                                                \
    $MYCONF                                                              &&
make
