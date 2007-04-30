if [[ "$(get_spell_provider $SPELL NS-PLUGIN-COMPATIBLE)" == "firefox" ]]; then
  sedit 's#$HOME/.firefox/plugins#$INSTALL_ROOT/usr/lib/firefox/plugins#g' configure &&
  sedit 's#$HOME/.mozilla/plugins#$INSTALL_ROOT/usr/lib/mozilla/plugins#g' configure
elif [[ "$(get_spell_provider $SPELL NS-PLUGIN-COMPATIBLE)" == "mozilla" ]]; then
  sedit 's#$HOME/.firefox/plugins#$INSTALL_ROOT/usr/lib/firefox/plugins#g' configure &&
  sedit 's#$HOME/.mozilla/plugins#$INSTALL_ROOT/usr/lib/mozilla/plugins#g' configure
fi &&

default_build
