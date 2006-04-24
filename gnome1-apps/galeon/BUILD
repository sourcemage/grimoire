(
  FOO=$(gaze installed mozilla | cut -d. -s -f1-3 | cut -c-3)
  ./configure  --prefix=${INSTALL_ROOT}/usr     \
               --sysconfdir=${INSTALL_ROOT}/etc  \
               --disable-werror                 \
               --with-mozilla-snapshot=$FOO     \
               $OPTS                       &&
  make                                     &&
  prepare_install                          &&
  make    install                          &&
  echo  "YES"                              |
  galeon-config-tool  --install-schemas --fix-gconf-permissions
#  &&
#   echo  "YES"                     |
#  gconftool  -install-schema-file /etc/gconf/schemas/galeon.schemas

) > $C_FIFO 2>&1
