 create_account "jabber" &&

  for f in $(find . -name "*" -type f); do
    sedit 's|/jabberd/log|/log/jabberd|' $f
  done &&

  if echo "$OPTS" | grep -q 'enable-db'; then STORAGE="$STORAGE db" && AUTHREG="$AUTHREG db"; fi &&
  if echo "$OPTS" | grep -q 'enable-mysql'; then STORAGE="$STORAGE mysql" && AUTHREG="$AUTHREG mysql"; fi &&
  if echo "$OPTS" | grep -q 'enable-pgsql'; then STORAGE="$STORAGE pgsql" && AUTHREG="$AUTHREG pgsql"; fi &&

  if echo "$OPTS" | grep -q 'enable-ldap'; then AUTHREG="$AUTHREG ldap"; fi &&
  if echo "$OPTS" | grep -q 'enable-pam'; then AUTHREG="$AUTHREG pam"; fi &&

  message "Storage drivers:$STORAGE" &&
  message "Authentication modules:$AUTHREG" &&

  ./configure \
    --build=$BUILD \
    --host=$HOST   \
    --prefix=$INSTALL_ROOT/usr \
    --sysconfdir=$INSTALL_ROOT/etc \
    --localstatedir=$INSTALL_ROOT/var \
    --enable-storage="$STORAGE" \
    --enable-authreg="$AUTHREG" \
    --enable-debug \
    $OPTS &&
  make
