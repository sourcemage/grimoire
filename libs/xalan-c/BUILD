if [[ $XAL_VER == release ]];then
  cd c
fi &&
export XALANCROOT=$PWD &&

if  [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]];  then
  ARCH=64
else
  ARCH=32
fi  &&

if is_depends_enabled $SPELL icu; then
  export ICUROOT=$INSTALL_ROOT/usr
fi &&

./runConfigure -p linux -b $ARCH -c gcc $OPTS -P $INSTALL_ROOT/usr &&

make_single  &&
make         &&
make_normal
