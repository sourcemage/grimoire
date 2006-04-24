# Readline bug fix
sed -e 's/char \*readline, (char \*)/char \*readline, (const char \*)/g' bc/scan.c > /tmp/scan.l &&
cp /tmp/scan.l ./bc/scan.l      &&
sed -e 's/char \*readline, (char \*)/char \*readline, (const char \*)/g' bc/scan.c > /tmp/scan.c &&
cp /tmp/scan.c ./bc/scan.c      &&
# x86_64 function fix found and contributed by Seth Woolley
patch -p1 < $SCRIPT_DIRECTORY/bc_x86_64.patch         &&

./configure --prefix=${INSTALL_ROOT}/usr              \
            --infodir=${INSTALL_ROOT}/usr/share/info  \
            --mandir=${INSTALL_ROOT}/usr/share/man    \
            --with-readline  && 
make
