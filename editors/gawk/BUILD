[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

# Disable mpfr and readline as that complicates upgrade
# of gmp ... which fails mid-way since sorcery really relies
# on awk to work. Proper fix would be to protect all
# base libraries during dispel, like libc. -- ThOr
./configure  --build=${BUILD}              \
             --prefix=${TRACK_ROOT}/usr  \
             --bindir=${TRACK_ROOT}/bin  \
             --sysconfdir=${TRACK_ROOT}/etc  \
             --infodir=${TRACK_ROOT}/usr/share/info \
             --mandir=${TRACK_ROOT}/usr/share/man   \
             --without-mpfr --without-readline \
             ${OPTS}  &&
make DESTDIR=$INSTALL_ROOT
