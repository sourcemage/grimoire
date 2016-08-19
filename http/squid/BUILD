sedit  "s:\$(localstatedir)/logs/squid\.pid:/var/run/squid\.pid:"  src/Makefile.in &&

# This must be set by CONFIGURE ideally
# See src/auth/ directory for a list of authentication protocols
# See helpers/*_auth/ directories for lists of authentication helpers
SQUID_AUTH_BASIC='' &&
SQUID_AUTH_DIGEST='' &&
SQUID_AUTH_NTLM='' &&

./configure                                          \
  --prefix=${INSTALL_ROOT}/usr                       \
  --sysconfdir=${INSTALL_ROOT}/etc/squid             \
  --localstatedir=${INSTALL_ROOT}/var/cache/squid    \
  --mandir=${INSTALL_ROOT}/usr/share/man             \
  --infodir=${INSTALL_ROOT}/usr/share/info           \
  --enable-async-io                                  \
  --enable-snmp                                      \
  --enable-removal-policies                          \
  --enable-linux-netfilter                           \
  --enable-auth                                      \
  --enable-auth-basic="$SQUID_AUTH_BASIC"            \
  --enable-digest-auth-helpers="$SQUID_AUTH_DIGEST"  \
  --enable-ntlm-auth-helpers="$SQUID_AUTH_NTLM"      \
    $SQUID_ARP_ACL                                   \
    $OPTS                                            &&                                          

make
