KVERSION=$(get_kernel_version)
if [[ "$FILE_SYSTEM" == 'y' ]] ; then
  export BUILD_DIRECTORY INSTALL_ROOT &&
  message "${MESSAGE_COLOR}Entering ${MKINITRD_SCRIPT}${DEFAULT_COLOR}" &&
  sh "${SCRIPT_DIRECTORY}/${MKINITRD_SCRIPT}" "${KVERSION}" &&
  message "${MESSAGE_COLOR}Done with ${MKINITRD_SCRIPT}${DEFAULT_COLOR}" &&
  if [[ "$EDIT_LINUXRC" == 'y' ]] && [[ -n "$EDITOR" ]]; then
    # if EDITOR is not set, the line below would *execute* linuxrc, which is
    # *highly* undesireable and may even be considered a security problem
    "$EDITOR" "$BUILD_DIRECTORY/initrd/linuxrc"
  fi 
fi
