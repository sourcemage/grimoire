create_account smtpd &&
create_account smtpq &&

OPTS="--with-ca-file=$INSTALL_ROOT/etc/ssl/certs/ca-certificates.crt \
      --with-privsep-user=smtpd \
      --with-queue-user=smtpq \
      $OPENSMTPD_OPTS \
      $OPTS" &&

default_build
