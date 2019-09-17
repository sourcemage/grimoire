case "$HOST" in
*-musl) OPTS+=' --config-musl' ;;
esac &&
if is_depends_enabled $SPELL gcc; then
  OPTS="--sysroot=$INSTALL_ROOT/usr \
        --crtprefix=$INSTALL_ROOT/usr/lib \
        --sysincludepaths=$INSTALL_ROOT/usr/include:$INSTALL_ROOT/usr/lib/tcc/include \
        --libpaths=$INSTALL_ROOT/lib:$INSTALL_ROOT/usr/lib\
        $OPTS"
fi &&

OPTS="$TCC_OPTS $OPTS" &&

default_build
