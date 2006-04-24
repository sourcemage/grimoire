  if spell_ok openssl; then
    SSL="--with-ssl=openssl"							&&
    mkdir -p /etc/ssl/certs							&&
    mkdir -p /etc/ssl/private
  else
    SSL=" "
  fi										&&

  PROTOCOLS=""                                                                  &&
  POP3D=""                                                                      &&

  if [ "$IMAP_BOOT" == "y" ]; then
    PROTOCOLS="$PROTOCOLS imap"
  fi                                                                            &&
  if [ "$IMAPS_BOOT" == "y" ]; then
    PROTOCOLS="$PROTOCOLS imaps"
  fi                                                                            &&
  if [ "$POP3_BOOT" == "y" ]; then
    PROTOCOLS="$PROTOCOLS pop3"							&&
    POP3D="--with-pop3d"
  fi                                                                            &&
  if [ "$POP3S_BOOT" == "y" ]; then
    PROTOCOLS="$PROTOCOLS pop3s"						&&
    POP3D="--with-pop3d"
  fi                                                                            &&

  if [ "$PROTOCOLS" == "" ]; then
    PROTOCOLS="none"
  fi                                                                            &&
  if [ "$POP3D" == "" ]; then
    POP3D="none"
  fi                                                                            &&

  if [ "$PROTOCOLS" == "none" ]; then
    message "${MESSAGE_COLOR}Error: dovecot must be configured for at least one protocol."	&&
    message "run cast -r -c dovecot again. ${DEFAULT_COLOR}"					&&
    return 1
  else
    message "${MESSAGE_COLOR}Using protocols: $PROTOCOLS ${DEFAULT_COLOR}"
  fi										&&

  if [ "$POP3D" == "none" ]; then
    POP3D="--without-pop3d"
  fi										&&

  ./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var 		\
              $IPV6 $SSL $POP3D $OPTS	 					&&
  make
