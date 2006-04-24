(

  # [SL] future patch
  #patch -p1 < $SCRIPT_DIRECTORY/conformance.patch &&

  prepare_install &&

  cp -df tedia2sql /usr/bin/ &&
  chmod +x /usr/bin/tedia2sql &&

  mkdir -p /usr/doc/$SPELL &&
  cp -dfR www/ /usr/doc/$SPELL/ &&
  cp -df AUTHORS LICENSE README /usr/doc/$SPELL/

) > $C_FIFO 2>&1 && (

  message "${MESSAGE_COLOR}Copy ${FILE_COLOR}/usr/doc/$SPELL/tedia2sqlrc${MESSAGE_COLOR} to ${FILE_COLOR}~/.tedia2sqlrc${MESSAGE_COLOR} and customize it.${DEFAULT_COLOR}"

)
