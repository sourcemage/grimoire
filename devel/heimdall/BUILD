OPTS="$OPTS --build=${BUILD}";
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}";
git reset --hard "v$VERSION" &&
for i in libpit heimdall; do
  cd "$i" &&
  ./configure \
    --prefix=${INSTALL_ROOT}/usr \
    --sysconfdir=${INSTALL_ROOT}/etc \
    --localstatedir=${INSTALL_ROOT}/var \
    --mandir=${INSTALL_ROOT}/usr/share/man \
    --infodir=${INSTALL_ROOT}/usr/share/info $OPTS &&
  make &&
  cd .. || exit
done
