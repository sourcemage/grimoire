#!/bin/sh
# $Id: mkconf.sh,v 1.5 2003/01/04 05:41:22 sergeyli Exp $

# full host name
HOST=$(hostname) &&
# domain name part
DOMAIN=${HOST#*\.} &&
# supposedly a company name
ORG=${DOMAIN%\.*} &&
# common LDAP tree suffix
SUFFIX="dc=${DOMAIN//\./,dc=}" &&
PASS=123456 &&

message "${MESSAGE_COLOR}Creating default slapd.conf${DEFAULT_COLOR}" &&

cat > /tmp/slapd.conf.default.$$ << __EOF__ &&
# See slapd.conf(5) for details on configuration options.
# This file should NOT be world readable.
#
# Auto-generated $NOW
# Change $SUFFIX to dc=company,dc=com for company.com
#
pidfile		/var/run/slapd.pid
argsfile	/var/run/slapd.args

schemacheck	on

include		/etc/openldap/schema/core.schema
include		/etc/openldap/schema/cosine.schema
include		/etc/openldap/schema/inetorgperson.schema
include		/etc/openldap/schema/nis.schema
#include		/etc/openldap/schema/misc.schema
#include		/etc/openldap/schema/openldap.schema
#include		/etc/openldap/schema/java.schema

#
# slapd provides ample logging, so enable this for debugging only
# consult slapd.conf(8) manpage for values
#
#loglevel	968

# The userPassword by default can be changed
# by the entry owning it if they are authenticated.
# Others should not be able to see it
#
# rootdn always has write access, just bind using its DN
#
access to attribute=userPassword
	by anonymous auth
	by self write
	by * none
access to *
	by * read

defaultsearchbase	"$SUFFIX"

#
# Save the time that the entry gets modified
#
lastmod on

#######################################################################
# Berkeley DB backend database definitions
#######################################################################

# Backend name
backend bdb

# Berkeley DB (DBD) will serve as a backend
database	bdb

# The database directory MUST exist prior to running slapd AND 
# should only be accessible by the slapd/tools. Mode 700 recommended.
directory	/var/openldap-data

# Indices to maintain
index	objectclass	eq
index	uid eq

suffix		"$SUFFIX"
rootdn		"cn=root,$SUFFIX"

# Cleartext passwords, especially for the rootdn, should
# be avoided.  See slappasswd(8) and slapd.conf(5) for details.
# Use of strong authentication encouraged.
# Default password (please change!): $PASS
rootpw		"$(slappasswd -s "$PASS")"
__EOF__

mv /tmp/slapd.conf.default.$$ /etc/openldap/slapd.conf.default &&
if ! [ -e /etc/openldap/slapd.conf ]; then
  cp /etc/openldap/slapd.conf.default /etc/openldap/slapd.conf
fi &&

message "${MESSAGE_COLOR}Creating default ldap.conf${DEFAULT_COLOR}" &&

cat > /tmp/ldap.conf.default.$$ << __EOF__ &&
# This is the configuration file for the LDAP nameservice
# switch library and the LDAP PAM module.
#
# PADL Software
# http://www.padl.com
#
# See ldap.conf from pam_ldap package for more options
#

# The distinguished name of the search base.
# Replace with suffix from slapd.conf
base	$SUFFIX

# Another way to specify your LDAP server is to provide an
# uri with the server name. This allows to use
# Unix Domain Sockets to connect to a local LDAP Server.
uri	ldap://127.0.0.1/
#uri ldaps://127.0.0.1/   
#uri ldapi://%2fvar%2frun%2fldapi_sock/
# Note: %2f encodes the '/' used as directory separator

# Filter to AND with uid=%s
# May speed up searches
pam_filter	objectclass=posixAccount

# Use the OpenLDAP password change
# extended operation to update the password.
pam_password exop

# LDAP protocol version
ldap_version 3
__EOF__

mv /tmp/ldap.conf.default.$$ /etc/ldap.conf.default &&
if ! [ -e /etc/ldap.conf ]; then
  cp /etc/ldap.conf.default /etc/ldap.conf
fi &&

message "${MESSAGE_COLOR}Creating sample LDIF for top hierarchy${DEFAULT_COLOR}" &&

cat > /tmp/top.ldif.$$ << __EOF__ &&
#
# Replace $SUFFIX with suffix from slapd.conf
# Use the following command to create th hierarchy:
# 	ldapadd -D "cn=root,$SUFFIX" -W -f /etc/openldap/top.ldif
#

dn: $SUFFIX
objectclass: dcObject
objectclass: organization
dc: $ORG
o: $ORG

dn: ou=Users,$SUFFIX
objectclass: organizationalUnit
ou: Users

dn: ou=Groups,$SUFFIX
objectclass: organizationalUnit
ou: Groups
__EOF__

mv /tmp/top.ldif.$$ /etc/openldap/top.ldif &&

message "${MESSAGE_COLOR}Creating sample LDIF for user and group creation${DEFAULT_COLOR}" &&

cat > /tmp/usergroup.ldif.$$ << __EOF__ &&
#
# Sample user and group LDIF file
# Replace $SUFFIX with suffix from slapd.conf
#

dn: cn=john,ou=Groups,$SUFFIX
objectClass: posixGroup
cn: john
userPassword: {CRYPT}x
gidNumber: 1001
memberuid: john

dn: cn=john,ou=Users,$SUFFIX
objectClass: account
objectClass: posixAccount
objectClass: shadowAccount
cn: john
uid: john
# Sample password: john
userPassword: `slappasswd -s "john"`
shadowLastChange: 11763
shadowMax: 99999
shadowWarning: 7
loginShell: /bin/sh
uidNumber: 1001
gidNumber: 1001
homeDirectory: /home/john
__EOF__

mv /tmp/usergroup.ldif.$$ /etc/openldap/usergroup.ldif &&

message "${MESSAGE_COLOR}Use $SCRIPT_DIRECTORY/mkaccount.sh${DEFAULT_COLOR}" &&
message "${MESSAGE_COLOR}to create LDIF for new account${DEFAULT_COLOR}"
