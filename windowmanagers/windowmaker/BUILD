if [[ "${SMGL_COMPAT_ARCHS[1]}" == alpha ]] || [[ "${SMGL_COMPAT_ARGS[1]}" != x86_64 ]]; then
  message "we are on alpha or x66_64, letting it PIC" &&
  default_build
else
  message "disabling PIC on non-alpha or non-x86_64 arch" &&
  OPTS="--without-pic ${OPTS}" &&
  disable_pic force            &&
  default_build
fi
