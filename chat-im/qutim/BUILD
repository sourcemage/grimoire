prepare_cmake_flags &&
qt4_cmake_build &&

if ! list_find "$QUTIM_PLUGINS" "none"
then
  for PLUGIN in $QUTIM_PLUGINS; do
    cd ${SOURCE_DIRECTORY}/plugins/$PLUGIN &&
    if [[ $PLUGIN == "jabber" ]] || [[ $PLUGIN == "mrim" ]]
    then
      mkdir -p build &&
      cd build &&
      cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr $OPTS ../ &&
      make
    else
      qt4_build
    fi
  done
fi
