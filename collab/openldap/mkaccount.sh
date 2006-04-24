#!/bin/sh
# $Id: mkaccount.sh,v 1.4 2002/09/23 21:43:00 sergeyli Exp $

if [ "$UID" != 0 ]; then
	echo "Switching to root..."
	su - -c "$PWD/$0 $*"
	exit
fi

echo "#"
echo "# Usage: $0 <login> <id> <password> <last name>"

echo "# `grep '${1:-nobody}' /etc/passwd`"

SUFFIX=`gawk '/^suffix\W+/ { match($0, /suffix\W+"?([^"]*)"?/, a); print a[1]; nextfile; }' /etc/openldap/slapd.conf`

# echo
if [ -z "$SUFFIX" ]; then
	HOST=`hostname`
	SUFFIX="o=${HOST#*.}"
fi

ID=${2:-1001}

cat << __EOF__
dn:           cn=$1,ou=Groups,$SUFFIX
objectClass:  posixGroup
cn:           $1
userPassword: {CRYPT}x
gidNumber:    $ID
memberuid:    $1

dn:               cn=$1,ou=Users,$SUFFIX
objectClass:      inetOrgPerson
objectClass:      posixAccount
objectClass:      shadowAccount
cn:               $1
sn:               ${4:-lastname}
givenName:        $1
mail:             $1@`hostname`
description:      Entry for \`$1($ID)' created `date +%c`
uid:              $1
userPassword:     `slappasswd -s "$3"`
shadowLastChange: $((`date +%s` / 60 / 60 / 24))
shadowMax:        99999
shadowWarning:    7
loginShell:       /bin/sh
uidNumber:        $ID
gidNumber:        $ID
homeDirectory:    /home/$1
__EOF__
