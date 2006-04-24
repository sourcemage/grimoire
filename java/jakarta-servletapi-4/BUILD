(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env			&&
# ToDo: use jaxp || xerces
  ant dist			&&
  
  prepare_install									&&
  
  extract_jakarta_src   ${PKG_NAME}  ${PKG_NAME}-${VERSION}     $SOURCE_DIRECTORY/dist	&&
  register_jakarta_jar  ${PKG_NAME}-${VERSION}/lib/servlet.jar  servlet.jar
  
) > $C_FIFO 2>&1
