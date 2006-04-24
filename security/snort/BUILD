create_account  snort  &&

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"

OPTS="--prefix=${INSTALL_ROOT}/usr             \
  --sysconfdir=${INSTALL_ROOT}/etc/snort       \
--localstatedir=${INSTALL_ROOT}/var            \
      --mandir=${INSTALL_ROOT}/usr/share/man   \
     --infodir=${INSTALL_ROOT}/usr/share/info  \
               ${OPTS}"                        &&

[     "$CF_SNMP"  ==  y  ]  &&  OPTS="$OPTS --with-snmp"
[      "$CF_SMB"  ==  y  ]  &&  OPTS="$OPTS --enable-smbalerts"
[    "$CF_FLEXR"  ==  y  ]  &&  OPTS="$OPTS --enable-flexresp"
[  "$CF_PERFMON"  ==  y  ]  &&  OPTS="$OPTS --enable-perfmonitor"
[    "$CF_MYSQL"  ==  y  ]  &&  OPTS="$OPTS --with-mysql"
[     "$CF_PSQL"  ==  y  ]  &&  OPTS="$OPTS --with-postgresql"
[      "$CF_ORA"  ==  y  ]  &&  OPTS="$OPTS --with-oracle"
[     "$CF_ODBC"  ==  y  ]  &&  OPTS="$OPTS --with-odbc"

./configure  $OPTS  &&
make                &&
make  check
