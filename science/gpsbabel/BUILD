PATH=${INSTALL_ROOT}/usr/bin/qt4:$PATH default_build &&
if is_depends_enabled $SPELL qt4; then
  pushd gui        &&
  ${TRACK_ROOT}/usr/bin/qt4/lrelease *.ts &&
  qt4_build &&
  popd
fi &&
if is_depends_enabled $SPELL perl; then
  perl xmldoc/makedoc &&
  make gpsbabel.html
fi
