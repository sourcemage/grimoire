if test "$(get_spell_provider $SPELL GECKO)" = "firefox"; then
  sedit  's/mozilla-plugin/firefox-plugin/'  configure
fi  &&
./configure --prefix=${INSTALL_ROOT}/usr  \
        --sysconfdir=${INSTALL_ROOT}/etc  \
     --localstatedir=${INSTALL_ROOT}/var  \
                     $MP_OPTS             \
                     $OPTS                &&
make
