(
  # Fix thanks to Lunar Linux's BUILD
  if [ -z "${DISPLAY}" ]
  then
    export  GTKDOC=false
    message  "${MESSAGE_COLOR}An X display was not found; disabling gtk-doc generation. If you want gtk-doc generation then recast ${SPELL_COLOR}libglade${MESSAGE_COLOR} in a console with access to an X window.${DEFAULT_COLOR}"
  fi  &&

  ./configure  --prefix=${INSTALL_ROOT}/usr  \
               --disable-gnomedb             \
               $OPTS                         &&
  make                                       &&
  prepare_install                            &&
  make    install

) > $C_FIFO 2>&1
