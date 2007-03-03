OPTS="--with-xml-names=${RAPTOR_XMLVERSION}  \
      --with-xml-parser=${RAPTOR_PARSER}     \
      --with-www=${RAPTOR_WWWLIB}            \
      ${OPTS}"                               &&

#
# Bash likes to muck with my quoted variables for RAPTOR_LIST
# so we're going to just send it along like so
#
./configure --prefix=${INSTALL_ROOT}/usr             \
        --sysconfdir=${INSTALL_ROOT}/etc             \
     --localstatedir=${INSTALL_ROOT}/var             \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
           --infodir=${INSTALL_ROOT}/usr/share/info  \
    --enable-parsers="$RAPTOR_LIST"                  \
                     $OPTS                           &&
make
