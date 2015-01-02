OPTS="--with-threads=$STUNNEL_THREADS \
                     $STUNNEL_OPTS \
                     $OPTS" &&

case "$CERTIFICATE" in
  y|Y|j|J)
    default_build &&
    rm -f /etc/stunnel/stunnel.pem
  ;;
  *)
    cp /etc/stunnel/stunnel.pem tools/  &&
    default_build
  ;;
esac
