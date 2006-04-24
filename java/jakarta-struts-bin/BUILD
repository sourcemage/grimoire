(

  . $SECTION_DIRECTORY/java-functions

  prepare_install									&&
  
  extract_jakarta_src   ${PKG_NAME}  ${PKG_NAME}-${VERSION}    $SOURCE_DIRECTORY        &&
  register_jakarta_jar  ${PKG_NAME}-${VERSION}/lib/struts.jar  struts.jar
  
) > $C_FIFO 2>&1
