(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env	&&

# ToDO: try to pass test
# ant test 

  ant  dist	&&
  
  prepare_install								&&
  
  extract_jakarta_dist  ${PKG_SUBPRJ}-${PKG_NAME} ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION} dist/${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}.tar.gz &&
  register_jakarta_jar  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}/commons-collections.jar  commons-collections.jar
    
) > $C_FIFO 2>&1
