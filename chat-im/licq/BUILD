OPTS="$OPTS -DBUILD_TESTS=off"
local_cmake_build()
{
  mkdir -p build        &&
  cd build              &&
  prepare_cmake_flags   &&
  cmake -DCMAKE_MODULE_PATH=${SOURCE_DIRECTORY}/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr -DSYSCONFDIR=$INSTALL_ROOT/etc $OPTS ../  &&
  make
}
local_qt4_cmake_build() {
  QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
  PATH="$QTDIR/bin/qt4:$PATH"
  local_cmake_build
}

cmake_build &&

if [[ "$LICQ_CDK" == "y" ]]; then
  cd  $SOURCE_DIRECTORY/plugins/console     &&
  local_cmake_build
fi            &&

if [[ "$LICQ_QT4GUI" == "y" ]]; then
  cd  $SOURCE_DIRECTORY/plugins/qt4-gui     &&
  local_qt4_cmake_build
fi &&

if [[ "$LICQ_MSN" == "y" ]] && ! list_find "$OPTS" "--disable-openssl"; then
  cd $SOURCE_DIRECTORY/plugins/msn           &&
  local_cmake_build
fi  &&

if [[ "$LICQ_FORWARDER" == "y" ]]; then
  cd $SOURCE_DIRECTORY/plugins/forwarder     &&
  local_cmake_build
fi &&

if [[ "$LICQ_AREP" == "y" ]]; then
  cd $SOURCE_DIRECTORY/plugins/auto-reply    &&
  local_cmake_build
fi &&

if [[ "$LICQ_RMS" == "y" ]]; then
  cd $SOURCE_DIRECTORY/plugins/rms           &&
  local_cmake_build
fi &&

if [[ "$LICQ_AOSD" == "y" ]]; then
  cd $SOURCE_DIRECTORY/plugins/aosd          &&
  local_cmake_build
fi &&
if [[ "$LICQ_XOSD" == "y" ]]; then
  cd $SOURCE_DIRECTORY/plugins/osd           &&
  local_cmake_build
fi
