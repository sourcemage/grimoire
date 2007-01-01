if [ ${SMGL_COMPAT_ARCHS[1]} != alpha ]; then
  message "disabling PIC on non-alpha arch" &&
  OPTS="--without-pic ${OPTS}" &&
  disable_pic force            &&
  default_build
else
  message "we are on alpha, letting it PIC" &&
  default_build
fi
