if test "$(get_spell_provider $SPELL GECKO)" = "firefox"; then
  sedit  's/mozilla-plugin/firefox-plugin/'  configure  &&
  if  ! ldd $INSTALL_ROOT/usr/lib/firefox/firefox-bin |
      grep -q libgtk-x11-2.0.so; then
    OPTS="--disable-gtk2 --enable-gtk1 $OPTS"
  fi
elif test "$(get_spell_provider $SPELL GECKO)" = "seamonkey"; then
  sedit  's/mozilla-plugin/seamonkey-plugin/'  configure
elif test "$(get_spell_provider $SPELL GECKO)" = "xulrunner"; then
  sedit  's/mozilla-plugin/xulrunner-plugin/'  configure
fi  &&
./configure --prefix=${INSTALL_ROOT}/usr  \
        --sysconfdir=${INSTALL_ROOT}/etc  \
     --localstatedir=${INSTALL_ROOT}/var  \
                     $MP_OPTS             \
                     $OPTS                &&
make
