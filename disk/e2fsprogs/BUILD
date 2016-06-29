OPTS="--disable-libblkid $OPTS" &&
OPTS="--disable-libuuid --disable-uuidd $OPTS" &&
OPTS="--disable-fsck $OPTS" &&

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=$HOST"

./configure --host=${BUILD} \
          --prefix=${TRACK_ROOT}/usr \
         --infodir=${TRACK_ROOT}/usr/share/info \
          --mandir=${TRACK_ROOT}/usr/share/man \
--with-root-prefix=${TRACK_ROOT} \
                   --enable-elf-shlibs \
                   ${E2FSPROGS_HARDEN} \
                   $OPTS &&

make DESTDIR="$INSTALL_ROOT"
