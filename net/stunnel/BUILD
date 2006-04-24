[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"

OPTS=" --prefix=${INSTALL_ROOT}/usr  \
   --sysconfdir=${INSTALL_ROOT}/etc  \
--localstatedir=${INSTALL_ROOT}/var  \
       --mandir=${INSTALL_ROOT}/usr/share/man   \
      --infodir=${INSTALL_ROOT}/usr/share/info  \
                $OPTS"


case  $CERTIFICATE  in

  y|Y|j|J)
    ./configure $OPTS                   &&
    make cert <<EOF                     &&
$COUNTRY_NAME
$PROVINCE_NAME
$LOCALITY_NAME
$ORG_NAME
$ORG_UNIT_NAME
$COMMON_NAME
EOF
    make all                            &&
    rm -f /etc/stunnel/stunnel.pem
  ;;

  *)
    cp /etc/stunnel/stunnel.pem tools/  &&
    ./configure $OPTS                   &&
    make all
  ;;

esac
