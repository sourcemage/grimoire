make prefix=${INSTALL_ROOT}/ exec_prefix=${INSTALL_ROOT}/ V=true ${OPTS}  &&
make EXTRAS="extras/run_directory" prefix=${INSTALL_ROOT}/ exec_prefix=${INSTALL_ROOT}/ ${OPTS} DEST_DIR="./" V=true &&

if [[ "$UDEV_STATIC" == 'y' ]]; then
  pushd __static__ &&
  # we are not going to use `make install' so no need to set its parameters
  message "${MESSAGE_COLOR}Building static utilities: $UDEV_STATIC_TARGET${DEFAULT_COLOR}"
  make USE_STATIC=true V=true $OPTS $UDEV_STATIC_TARGET &&
  popd
fi
