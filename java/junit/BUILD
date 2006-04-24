(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env				&&
  
  ${JAVA_HOME}/bin/jar  -xf  src.jar	&&   
  ant					&&
  
  prepare_install			&&
  
  extract_ibm_src   ${SPELL} ${SPELL}${VERSION}   ${SOURCE_DIRECTORY}/${SPELL}${VERSION}  &&
  register_ibm_jar  ${SPELL}${VERSION}/junit.jar  junit.jar

) > $C_FIFO 2>&1
