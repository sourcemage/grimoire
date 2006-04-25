sed -i "s|/local||" Makefile              &&
#keep only enabled options
grep "\"y\"" $SPELL_CONFIG.p >>.config    &&
# bypass bug in Makefile
  sed -i "s|IFACE=y|IFACE=unix|" .config  &&
  make                                    &&
# Build GUI
if [ "$WPA_GUI" == "y" ]; then
  make wpa_gui
fi
