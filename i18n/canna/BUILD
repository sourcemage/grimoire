sed -i "s:/usr/local/canna:${INSTALL_ROOT}/usr:"             Canna.conf  &&
sed -i "s:/usr/spool/canna:${INSTALL_ROOT}/var/spool/canna:" Canna.conf  &&
sed -i 's:$(cannaPrefix)/man:$(cannaPrefix)/share/man:'      Canna.conf  &&
xmkmf            &&
make Makefiles   &&
make canna

