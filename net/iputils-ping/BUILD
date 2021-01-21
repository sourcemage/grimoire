case "$HOST" in
  (*-musl)
    CFLAGS+=' -DAI_CANONIDN=0'
    ;;
esac &&
make CC="${CC:-cc}" TARGETS=ping &&
if is_depends_enabled $SPELL opensp ; then
  make_single &&
  make -C doc man &&
  make_normal
fi
