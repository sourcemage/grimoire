if [[ "${CIMG_EXAMPLES}" == "y" ]]
then
  cd examples  &&

  sedit "s:CFLAGS   =:CFLAGS   = ${CFLAGS}:" Makefile   &&
  sedit "s:LDFLAGS  =:LDFLAGS  = ${LDFLAGS}:" Makefile  &&
  sedit "s:/usr:${INSTALL_ROOT}/usr:" Makefile  &&
  sedit "s:/X11R6::" Makefile  &&
  if ! is_depends_enabled ${SPELL} libxext
  then
    sedit "s:CIMG_XSHM_FLAGS:#CIMG_XSHM_FLAGS:" Makefile
  fi  &&
  if ! is_depends_enabled ${SPELL} libxrandr
  then
    sedit "s:CIMG_XRANDR_FLAGS:#CIMG_XRANDR_FLAGS:" Makefile
  fi  &&
  if is_depends_enabled ${SPELL} fftw
  then
    sedit "s:#CIMG_FFTW3_FLAGS:CIMG_FFTW3_FLAGS:" Makefile
  fi  &&
  if is_depends_enabled ${SPELL} imagemagick
  then
    sedit "s:#CIMG_MAGICK_FLAGS:CIMG_MAGICK_FLAGS:" Makefile
  fi  &&
  if is_depends_enabled ${SPELL} jpeg
  then
    sedit "s:#CIMG_JPEG_FLAGS:CIMG_JPEG_FLAGS:" Makefile
  fi  &&
  if is_depends_enabled ${SPELL} libpng
  then
    sedit "s:#CIMG_PNG_FLAGS:CIMG_PNG_FLAGS:" Makefile
  fi  &&
  if is_depends_enabled ${SPELL} tiff
  then
    sedit "s:#CIMG_TIFF_FLAGS:CIMG_TIFF_FLAGS:" Makefile
  fi  &&

  make olinux
fi  &&

true
