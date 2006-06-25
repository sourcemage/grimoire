make prefix=${INSTALL_ROOT}/ exec_prefix=${INSTALL_ROOT}/ V=true   \
     ${OPTS} ${UDEV_DEBUG} &&
make EXTRAS="extras/run_directory extras/cdrom_id extras/firmware" \
     prefix=${INSTALL_ROOT}/ exec_prefix=${INSTALL_ROOT}/ ${OPTS}  \
     ${UDEV_DEBUG} DEST_DIR="./" V=true &&

if [[ "$UDEV_EXTRAS" == 'y' ]]; then
  make EXTRAS="extras/ata_id extras/dasd_id extras/edd_id extras/floppy extras/scsi_id extras/usb_id extras/volume_id" \
       prefix=${INSTALL_ROOT}/ exec_prefix=${INSTALL_ROOT}/ ${OPTS} \
       ${UDEV_DEBUG} DEST_DIR="./" V=true 
fi

#if [[ "$UDEV_STATIC" == 'y' ]]; then
#  pushd __static__ &&
#  # we are not going to use `make install' so no need to set its parameters
#  message "${MESSAGE_COLOR}Building static utilities: $UDEV_STATIC_TARGET${DEFAULT_COLOR}" &&
#  make USE_STATIC=true V=true $OPTS $UDEV_STATIC_TARGET &&
#  popd
#fi
