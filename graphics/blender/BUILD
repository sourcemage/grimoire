if list_find "$OPTS" "WITH_BF_ODE=1"; then
  sed -i "s:LIBDIR + '/ode':\'$INSTALL_ROOT/usr\':" config/linux2-config.py
fi &&

scons BF_INSTALLDIR="$SOURCE_DIRECTORY/install" \
      WITH_BF_INTERNATIONAL=1 \
      WITH_BF_PLAYER=1 \
      WITH_BF_GAMEENGINE=1 \
      $OPTS &&

make -C "$SOURCE_DIRECTORY/install/plugins"
