if [[ $(get_spell_provider $SPELL QT) == "qt4" ]]
then
# help configure to find needed QT4 binaries
# if not exported, configure doesn't find them
  export MOC="${INSTALL_ROOT}/usr/bin/qt4/moc"
  export RCC="${INSTALL_ROOT}/usr/bin/qt4/rcc"
  export UIC="${INSTALL_ROOT}/usr/bin/qt4/uic"
fi &&
default_build
