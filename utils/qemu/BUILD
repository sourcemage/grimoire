message "${MESSAGE_COLOR}Target list: $QEMU_ARCHS${DEFAULT_COLOR}" &&

cd "${SOURCE_DIRECTORY}"                    &&

./configure --prefix="$INSTALL_ROOT/usr"    \
            --sysconfdir="$INSTALL_ROOT/etc" \
            --target-list="$QEMU_ARCHS"     \
            --audio-drv-list="$QEMU_AUDIO"  \
            $QEMU_KVM                       \
            $QEMU_VNC                       \
            $QEMU_TPM                       \
            $OPTS                           &&

# Pass down ARFLAGS to workaround a bug in QEMU's build system
ARFLAGS=rv make
