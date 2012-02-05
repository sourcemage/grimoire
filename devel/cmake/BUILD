CXXFLAGS="${CXXFLAGS} -mno-avx" CFLAGS="${CFLAGS} -mno-avx" ./configure --prefix=${INSTALL_ROOT}/usr  \
           --datadir=/share/${SPELL}      \
            --docdir=/share/doc/${SPELL}  \
            --mandir=/share/man           \
            --parallel=${MAKE_NJOBS}      \
            $OPTS                         &&
make
