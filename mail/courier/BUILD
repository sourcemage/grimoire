create_account  courier                                       &&

case  "${COURIER_SSLWEBMAIL}"  in
    yes)                   OPTS="$OPTS  --enable-https"
                           ;;
    login_only)            OPTS="$OPTS  --enable-https=login"
                           ;;
    user_decides_via_url)  OPTS="$OPTS  --enable-https=auto"
                           ;;
    deafult)               OPTS="$OPTS  --enable-https=login  \
                                        --enable-https=auto"
                           ;;
    no)                    OPTS="$OPTS  --disable-https"
                           ;;
esac                                                          &&

OPTS="${COURIER_OPTS}                                         \
      ${COURIER_IMAPBUGS}                                     \
      ${COURIER_TRASHQUOTA}                                   \
         --sysconfdir=${INSTALL_ROOT}/etc/courier             \
      --localstatedir=${INSTALL_ROOT}/var/courier             \
      --datadir=${INSTALL_ROOT}/usr/share/courier             \
      --with-shellpath=${PATH}                                \
      --disable-root-check                                    \
      --with-mailuser=courier                                 \
      --with-mailgroup=courier                                \
      ${OPTS}"                                                &&

default_build
