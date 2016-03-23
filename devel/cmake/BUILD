# Add the path to qmake here instead of DEPENDS.
# This depends on our installation, not user choice.
if echo "$OPTS" | grep -q -- -qt-gui; then
  OPTS="$OPTS --qt-qmake=$INSTALL_ROOT/opt/qt4/bin/qmake"
fi &&
./configure --prefix=${INSTALL_ROOT}/usr  \
           --datadir=/share/${SPELL}      \
            --docdir=/share/doc/${SPELL}  \
            --mandir=/share/man           \
            --parallel=${MAKE_NJOBS}      \
            $OPTS                         &&
make
