message "${MESSAGE_COLOR}Target list: $QEMU_ARCHS${DEFAULT_COLOR}" &&

cd "${SOURCE_DIRECTORY}"                    &&

./configure --prefix="$INSTALL_ROOT/usr"    \
            --sysconfdir="$INSTALL_ROOT/etc" \
            --target-list="$QEMU_ARCHS"     \
            --audio-drv-list="$QEMU_AUDIO"  \
            --audio-card-list="$QEMU_CARDS" \
            $QEMU_KVM                       \
            $OPTS                           &&

make
