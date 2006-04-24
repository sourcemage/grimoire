(
  if ! (( $USE_CANNA+$USE_WNN )) ; then
    message "You need at least one dictionary server for kinput2 to function!"
    false
  fi                                            &&
  
  sedit "s/#define UseSj3//" Kinput2.conf       &&

  if ! (( $USE_CANNA )) ; then
    sedit "s/#define UseCanna//" Kinput2.conf
  fi                                            &&
  if (( $USE_WNN )) ; then
    sedit "s/\/\* #define UseWnn \*\//#define UseWnn/" Kinput2.conf &&
    sedit "s/^WNN/XCOMM _WNN/" Kinput2.conf                         &&
    sedit "s/XCOMM WNN/WNN/" Kinput2.conf
  fi                                            &&

  sedit "s/\/usr\/X11R6/\/usr/" Kinput2.conf    &&
  sedit "s/\/usr\/local/\/usr/" Kinput2.conf    &&
  sedit "s/\/usr\/canna/\/usr/" Kinput2.conf    &&
  sedit "s/\/usr/${INSTALL_ROOT//\//\\\/}\/usr/" Kinput2.conf &&

  xmkmf 					&&
  make Makefiles				&&
  make						&&
  prepare_install				&&
  make install
) > $C_FIFO 2>&1
