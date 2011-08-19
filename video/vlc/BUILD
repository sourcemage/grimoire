OPTS="--disable-dependency-tracking --disable-macosx-defaults $OPTS"  &&

if  [  "$V4L" = "y"  ];  then
  OPTS="--enable-v4l $OPTS"
fi  &&


if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  OPTS="MOZILLA_CONFIG=${INSTALL_ROOT}/usr/lib/firefox/firefox-config XPIDL=${INSTALL_ROOT}/usr/lib/firefox/ XPIDL_INCL=-I${INSTALL_ROOT}/usr/share/idl/firefox $OPTS"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = icecat; then
  OPTS="MOZILLA_CONFIG=${INSTALL_ROOT}/usr/bin/icecat-config XPIDL=${INSTALL_ROOT}/usr/lib/icecat/xpidl XPIDL_INCL=-I${INSTALL_ROOT}/usr/share/idl/icecat $OPTS"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="MOZILLA_CONFIG=${INSTALL_ROOT}/usr/bin/seamonkey-config XPIDL=${INSTALL_ROOT}/usr/lib/seamonkey/xpidl XPIDL_INCL=-I${INSTALL_ROOT}/usr/share/idl/seamonkey $OPTS"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
  OPTS="MOZILLA_CONFIG=${INSTALL_ROOT}/usr/bin/xulrunner-config XPIDL=${INSTALL_ROOT}/usr/lib/xulrunner/xpidl XPIDL_INCL=-I${INSTALL_ROOT}/usr/share/idl/xulrunner $OPTS"  &&
  CPPFLAGS="$CPPFLAGS -I${INSTALL_ROOT}/usr/include/nspr"
fi  &&

# help configure to find needed QT4 binaries
# if not exported, configure doesn't find them
if is_depends_enabled $SPELL qt4; then
        export MOC="${INSTALL_ROOT}/usr/bin/qt4/moc"
        export RCC="${INSTALL_ROOT}/usr/bin/qt4/rcc"
        export UIC="${INSTALL_ROOT}/usr/bin/qt4/uic"
fi  &&

if is_depends_enabled $SPELL goom; then
  LDFLAGS=${LDFLAGS/-Wl,--as-needed}
fi &&

default_build  &&

export -n MOC RCC UIC  &&
unset MOC RCC UIC
