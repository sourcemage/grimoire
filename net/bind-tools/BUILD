disable_reject_underlinking &&
muon setup \
                   -Dprefix=${INSTALL_ROOT}/usr \
                -Dbuildtype=release \
          -Ddefault_library=shared \
                   -Dlibdir=lib \
                  -Dfuzzing=disabled \
               -Dstats-json=disabled \
                  $OPTS \
                  builddir &&
samu -C builddir \
	delv \
	dig \
	dnssec-dsfromkey \
	dnssec-importkey \
	dnssec-keyfromlabel \
	dnssec-keygen \
	dnssec-revoke \
	dnssec-settime \
	dnssec-signzone \
	dnssec-verify \
	host \
	nslookup \
	nsupdate
