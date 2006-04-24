#!/bin/sh
# $Id: mksscert.sh,v 1.3 2002/11/04 18:48:15 sergeyli Exp $

function generate_self_signed_certificate() {
    local -r CONF_DIR=/etc/httpd

#
# These may be different
    local -r KEY_DIR=$CONF_DIR/ssl
    local -r CSR_DIR=$CONF_DIR/ssl
    local -r CRT_DIR=$CONF_DIR/ssl
    local -r CRR_DIR=$CONF_DIR/ssl

#
# CA attributes
    local -r CA_KEY=$KEY_DIR/ca-key.pem
    local -r CA_CRT=$CRT_DIR/ca-certificate.pem
    local -r CA_SRL=$CRT_DIR/ca-serial
    local -r CA_CRR=$CRR_DIR/ca-revokereq.pem

#
# SERVICE attributes
    local -r SERVICE=${1:-httpd}
    local -r SERVICE_KEY=$KEY_DIR/$SERVICE-key.pem
    local -r SERVICE_CSR=$CSR_DIR/$SERVICE-signreq.pem
    local -r SERVICE_CRT=$CRT_DIR/$SERVICE-certificate.pem
    local -r SERVICE_CLR=$CRR_DIR/$SERVICE-revokereq.pem

#
# Custom attributes
    local RSA_BITS=2048
    local TIMESTAMP=`date +%Y%m%d%H%M%S`
    local RANDOMIZE='-rand /var/log/wtmp:/var/log/syslog'

#
# Only allow file reading by owner after it's created
    umask 277

#
# Step 0a. Directories
    mkdir -p $CRT_DIR $KEY_DIR $CSR_DIR $CRR_DIR

#
# Step 1a. CA keys
    if [ -e $CA_KEY ]; then
	echo "-=* CA key: $CA_KEY *=-"
    else
	echo "-=* Generating CA key: $CA_KEY *=-"
	openssl genrsa $RANDOMIZE -out $CA_KEY $RSA_BITS || exit
  #
  # New key means new new certificate
	if [ -e $CA_CRT ]; then mv -fv $CA_CRT $CA_CRT.$TIMESTAMP; fi
	if [ -e $CA_CRR ]; then mv -fv $CA_CRR $CA_CRR.$TIMESTAMP; fi
    fi

#
# Step 1c. CA certificate, self-signed by CA itself
    if [ -e $CA_CRT ]; then
	echo "-=* CA certificate: $CA_CRT *=-"
    else
	echo "-=* Generating CA certificate: $CA_CRT *=-"
	openssl req -new -x509 -days 2048 -key $CA_KEY -out $CA_CRT || exit
    fi

#
# Step 1d. CA certificate revocation request (CRR), just in case

# TODO: do it

#
# Step 2a. Server keys
    if [ -e $SERVICE_KEY ]; then
	echo "-=* Server key: $SERVICE_KEY *=-"
    else
	echo "-=* Generating server key: $SERVICE_KEY *=-"
	openssl genrsa $RANDOMIZE -out $SERVICE_KEY $RSA_BITS || exit

  #
  # New key means new certificate
	if [ -e $SERVICE_CSR ]; then mv -fv $SERVICE_CSR $SERVICE_CSR.$TIMESTAMP; fi
	if [ -e $SERVICE_CRT ]; then mv -fv $SERVICE_CRT $SERVICE_CRT.$TIMESTAMP; fi
	if [ -e $SERVICE_CRR ]; then mv -fv $SERVICE_CRR $SERVICE_CRR.$TIMESTAMP; fi
    fi

#
# Step 2b. Server certificate signing request
    if [ -e $SERVICE_CSR ]; then
	echo "-=* Server certificate signing request: $SERVICE_CSR *=-"
    elif ! [ -e $SERVICE_CRT ]; then
	echo "-=* Generating server certificate signing request: $SERVICE_CSR *=-"
	echo "Specify server's FQDN as Common Name (CN)"
	openssl req -new -key $SERVICE_KEY -out $SERVICE_CSR || exit
    fi

#
# Step 2c. Server certificate, signed by CA
    if [ -s $SERVICE_CRT ]; then
	echo "-=* Server certificate: $SERVICE_CRT *=-"
    else
	if [ -e $SERVICE_CRT ]; then
	    echo "-=* Deleting zero-length server certificate: $SERVICE_CRT *=-"
	    rm -f $SERVICE_CRT
	fi

	echo "-=* Generating server certificate: $SERVICE_CRT *=-"
	if ! [ -w $CA_SRL ]; then
	    if ! [ -s $CA_SRL ]; then echo "01" > $CA_SRL; fi
	    chmod u+rw $CA_SRL
	fi
	openssl x509 -days 1024 -CA $CA_CRT -CAkey $CA_KEY -CAserial $CA_SRL -in $SERVICE_CSR -req -out $SERVICE_CRT || exit
	echo "-=* Done! *=-"
    fi
}

#
# Step 2d. Server certificate revocation request (CRR), just in case

# TODO: do it

#
# Switch context to root if we're not the one
if [ "$UID" != 0 ]; then
    echo "Switching to root..."
    su - -c "$PWD/$0 $*"
    exit
fi

#
# Main function
generate_self_signed_certificate "$@"
