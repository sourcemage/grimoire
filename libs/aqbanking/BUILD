./configure --build=${BUILD}                           \
            --host=${HOST}                             \
            --prefix=${INSTALL_ROOT}/usr               \
            --sysconfdir=${INSTALL_ROOT}/etc           \
            --localstatedir=${INSTALL_ROOT}/var        \
            --mandir=${INSTALL_ROOT}/usr/share/man     \
            --infodir=${INSTALL_ROOT}/usr/share/info   \
            --with-backends="${AQ_BACK}"               \
            --with-imexporters="${AQ_EXIM}"            \
            --with-parsers="${AQ_PARSE}"               \
            --with-bankinfos="${AQ_INFO}"              \
	    --disable-tutorials			       \
            $OPTS                                      &&
make_single  &&
make         &&
#make_normal
