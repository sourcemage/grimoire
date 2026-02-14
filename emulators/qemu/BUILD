# remove -ffast-math; hardfloat requires an exact IEEE implementation
CFLAGS="${CFLAGS//-ffast-math}" &&

message "${MESSAGE_COLOR}Target list: $QEMU_ARCHS${DEFAULT_COLOR}" &&

cd "${SOURCE_DIRECTORY}"                    &&

if [[ "x${QEMU_VNC_TLS}" == "xnone" ]]; then
  OPTS="${OPTS} --disable-gcrypt --disable-nettle"
fi  &&

case "$HOST" in
  (*-musl)
    OPTS+=' --disable-fuse'
    ;;
esac &&

./configure --prefix="$INSTALL_ROOT/usr"    \
            --sysconfdir="$INSTALL_ROOT/etc" \
            --localstatedir="$INSTALL_ROOT/var" \
            --target-list="${QEMU_ARCHS// /,}"  \
            --audio-drv-list="${QEMU_AUDIO// /,}" \
            --enable-fdt="internal" \
            $QEMU_OPTS                      \
            $OPTS                           &&

# slightly modified upstream fix for libfdt
patch -p1 < "${SPELL_DIRECTORY}/fix-discarded-const.patch" &&

# Pass down ARFLAGS to workaround a bug in QEMU's build system
ARFLAGS=rv make
