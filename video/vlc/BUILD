if  [  "$JOYSTICK"  =  "y"  ];  then
  export OPTS="$OPTS --enable-joystick"
fi  &&
if  [  "$V4L" = "y"  ];  then
  export OPTS="$OPTS --enable-v4l"
fi  &&

export OPTS="$OPTS --disable-dependency-tracking --enable-release"  &&

if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  OPTS="$OPTS MOZILLA_CONFIG=${INSTALL_ROOT}/usr/lib/firefox/firefox-config XPIDL=${INSTALL_ROOT}/usr/lib/firefox/ XPIDL_INCL=-I${INSTALL_ROOT}/usr/share/idl/firefox"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = iceweasel; then
  OPTS="$OPTS MOZILLA_CONFIG=${INSTALL_ROOT}/usr/bin/iceweasel-config XPIDL=${INSTALL_ROOT}/usr/lib/iceweasel/xpidl XPIDL\
_INCL=-I${INSTALL_ROOT}/usr/share/idl/iceweasel"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="$OPTS MOZILLA_CONFIG=${INSTALL_ROOT}/usr/bin/seamonkey-config XPIDL=${INSTALL_ROOT}/usr/lib/seamonkey/xpidl XPIDL_INCL=-I${INSTALL_ROOT}/usr/share/idl/seamonkey"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
  OPTS="$OPTS MOZILLA_CONFIG=${INSTALL_ROOT}/usr/bin/xulrunner-config XPIDL=${INSTALL_ROOT}/usr/lib/xulrunner/xpidl XPIDL_INCL=-I${INSTALL_ROOT}/usr/share/idl/xulrunner"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
fi  &&

# needs to be exported so vlc configure sees it, no idea why
export CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/dirac"  &&

sedit  's/libavcodec, libavformat/\0, libpostproc/'  configure

make_single    &&
default_build  &&
make_normal    &&

unset CPPFLAGS
