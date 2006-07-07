sedit  "s:\$(localstatedir)/logs/squid\.pid:/var/run/squid\.pid:"  src/Makefile.in &&

# This must be set by CONFIGURE ideally
# See src/auth/ directory for a list of authentication protocols
SQUID_AUTH=basic &&
# See helpers/*_auth/ directories for lists of authentication helpers
SQUID_AUTH_DIGEST='' &&
SQUID_AUTH_NTLM='' &&

./configure                                          \
  --prefix=/usr                                      \
  --sysconfdir=/etc/squid                            \
  --localstatedir=/var/cache/squid                   \
  --enable-async-io                                  \
  --enable-snmp                                      \
  --enable-removal-policies                          \
  --enable-linux-netfilter                           \
  --enable-auth="$SQUID_AUTH"                        \
  --enable-digest-auth-helpers="$SQUID_AUTH_DIGEST"  \
  --enable-ntlm-auth-helpers="$SQUID_AUTH_NTLM"      \
    $SQUID_ARP_ACL                                   \
    $OPTS                                            &&                                          

make
