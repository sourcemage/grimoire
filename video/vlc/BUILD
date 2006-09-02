if  [  "$JOYSTICK"  =  "y"  ];  then
  export OPTS="$OPTS --enable-joystick"
fi  &&
if  [  "$V4L" = "y"  ];  then
  export OPTS="$OPTS --enable-v4l"
fi  &&

export OPTS="$OPTS --disable-dependency-tracking --enable-release"  &&

if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  OPTS="$OPTS MOZILLA_CONFIG=/usr/bin/firefox-config XPIDL=/usr/lib/firefox/xpidl XPIDL_INCL=-I/usr/share/idl/firefox"  &&
  CPPFLAGS="$CPPFLAGS -I/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="$OPTS MOZILLA_CONFIG=/usr/bin/seamonkey-config XPIDL=/usr/lib/seamonkey/xpidl XPIDL_INCL=-I/usr/share/idl/seamonkey"  &&
  CPPFLAGS="$CPPFLAGS -I/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
  OPTS="$OPTS MOZILLA_CONFIG=/usr/bin/xulrunner-config XPIDL=/usr/lib/xulrunner/xpidl XPIDL_INCL=-I/usr/share/idl/xulrunner"  &&
  CPPFLAGS="$CPPFLAGS -I/usr/include/nspr"
fi  &&

# needs to be exported so vlc configure sees it, no idea why
export CPPFLAGS="$CPPFLAGS -I/usr/include/dirac"  &&

sedit  's/libavcodec, libavformat/\0, libpostproc/'  configure

make_single    &&
default_build  &&
make_normal    &&

unset CPPFLAGS
