. $GRIMOIRE/is_depends_enabled.function &&

if is_depends_enabled $SPELL firefox; then
  sedit 's#$HOME/.firefox/plugins#$INSTALL_ROOT/usr/lib/firefox/plugins#g' configure &&
  sedit 's#$HOME/.mozilla/plugins#$INSTALL_ROOT/usr/lib/mozilla/plugins#g' configure
fi &&

if is_depends_enabled $SPELL mozilla; then
  sedit 's#$HOME/.firefox/plugins#$INSTALL_ROOT/usr/lib/firefox/plugins#g' configure &&
  sedit 's#$HOME/.mozilla/plugins#$INSTALL_ROOT/usr/lib/mozilla/plugins#g' configure
fi &&

OPTS="$OPTS --enable-gui=$GNASH_GUI --enable-sound=$GNASH_SOUND" &&
default_build
