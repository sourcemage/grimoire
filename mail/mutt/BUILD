OPTS="--build=${BUILD}
      --with-mailpath=/var/spool/mail
      --with-docdir=${INSTALL_ROOT}/usr/share/doc/mutt
      ${MUTT_OPTS}
      ${TMP_MUTT_OPTS}
      ${OPTS}
" &&

default_build &&

if [ "${UPDATE_DOC}" == "y" ]; then
  make update-doc
fi
