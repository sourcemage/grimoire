(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env		&&
  ant pack-bin		&&
  
  prepare_install										   &&
  
  extract_jakarta_dist  ${PKG_NAME} ${PKG_NAME}-${VERSION} build/${PKG_NAME}-${VERSION}-bin.tar.gz &&
  register_jakarta_jar ${PKG_NAME}-${VERSION}/crimson.jar  crimson.jar
  
) > $C_FIFO 2>&1
