#!/bin/sh
# Generates a self-signed certificate.

OPENSSL=${OPENSSL-openssl}
SSLDIR=${SSLDIR-/etc/ssl}

if [ -e /etc/dovecot-openssl.cnf ]; then
  OPENSSLCONFIG="/etc/dovecot-openssl.cnf"
else if [ -e /etc/dovecot-openssl-example.cnf ]; then
    OPENSSLCONFIG="/etc/dovecot-openssl-example.cnf"
  else
    echo "/etc/dovecot-openssl-*.cnf file missing. Unable to generate ssl certificate and key file."
    exit 1
  fi
fi

CERTFILE=$SSLDIR/certs/imapd.pem
 KEYFILE=$SSLDIR/private/imapd.pem

TMPCF=/tmp/.c.pem
TMPKF=/tmp/.k.pem

if [ ! -d $SSLDIR/certs ]; then
  echo $SSLDIR/certs directory doesn't exist
fi

if [ ! -d $SSLDIR/private ]; then
  echo $SSLDIR/private directory doesn't exist
fi

$OPENSSL req -new -x509 -nodes -config $OPENSSLCONFIG -out $TMPCF -keyout $TMPKF || exit 2
chmod 0600 $TMPKF
$OPENSSL x509 -subject -fingerprint -noout -in $TMPCF || exit 2

if [ -f $CERTFILE ]; then
  echo "$CERTFILE already exists, won't overwrite"
else
  cp $TMPCF $CERTFILE
fi

if [ -f $KEYFILE ]; then
  echo "$KEYFILE already exists, won't overwrite"
else
  cp $TMPKF $KEYFILE
fi

rm -f $TMPKF $TMPCF

exit 0
