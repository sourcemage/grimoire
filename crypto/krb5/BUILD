if [ "$KRB4" == "y" ]; then
    OPTS="$OPTS --with-krb4"
else
    OPTS="$OPTS --without-krb4"
fi

cd  $SPELL-$VERSION/src                 &&

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
