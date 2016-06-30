message "${MESSAGE_COLOR}Target list: $QEMU_ARCHS${DEFAULT_COLOR}" &&

cd "${SOURCE_DIRECTORY}"                    &&

if [[ "x${QEMU_VNC_TLS}" == "xnone" ]]; then
  OPTS="${OPTS} --disable-gcrypt --disable-nettle"
fi  &&

./configure --prefix="$INSTALL_ROOT/usr"    \
            --sysconfdir="$INSTALL_ROOT/etc" \
            --localstatedir="$INSTALL_ROOT/var" \
            --target-list="$QEMU_ARCHS"     \
            --audio-drv-list="$QEMU_AUDIO"  \
            --python=python2                \
            $QEMU_KVM                       \
            $QEMU_VNC                       \
            $QEMU_TPM                       \
            $OPTS                           &&

# Pass down ARFLAGS to workaround a bug in QEMU's build system
ARFLAGS=rv make
