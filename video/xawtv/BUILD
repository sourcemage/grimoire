sedit  "s/gzip/gzip -f/"  Makefile.in      &&
# xawtv is incompatible with libquicktime >= 0.9.8, bug #10798
OPTS="--disable-quicktime $OPTS"           &&
default_build                              &&
#./configure  --prefix=${INSTALL_ROOT}/usr  \
#             --infodir=/usr/share/info     \
#             --mandir=/usr/share/man       \
#             ${OPTS}                       &&
#make                                       &&
# Compile fonts
cd  ${SOURCE2/.tar.bz2/}                   &&
make                                       &&
cd  ..
