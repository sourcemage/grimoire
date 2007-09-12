if [ "$KRB4" == "y" ]; then
    OPTS="$OPTS --with-krb4"
else
    OPTS="$OPTS --without-krb4"
fi

cd  $SPELL-$VERSION/src                 &&

# Kerberos Security Advisories
patch -p1 < $SCRIPT_DIRECTORY/MITKRB5-SA-2007-006.txt &&

./configure  --enable-dns-for-kdc       \
             --enable-dns-for-realm     \
             --infodir=/usr/share/info  \
             --mandir=/usr/share/man    \
             --enable-shared            \
             --prefix=/usr              \
             --localstatedir=/var       \
             $OPTS                      &&
make_single                             &&
make
