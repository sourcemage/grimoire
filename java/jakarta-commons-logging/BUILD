(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env		&&
  export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar" &&
  
  # create build.properties
  cat > $SOURCE_DIRECTORY/logging/build.properties <<EOF
log4j.jar=${SM_JAKARTA_HOME}/lib/log4j.jar
logkit.jar=${SM_JAKARTA_HOME}/lib/logkit.jar
junit.jar=${SM_IBM_HOME}/lib/junit.jar
EOF

  cd logging			&&
  cp LICENSE.txt ../LICENSE	&&
  ant  dist test		&&
    
  prepare_install								&&
  
  extract_jakarta_src   ${PKG_SUBPRJ}-${PKG_NAME}   ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}    $SOURCE_DIRECTORY/logging/dist	&&
  register_jakarta_jar  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}/commons-logging-api.jar  commons-logging-api.jar &&
  register_jakarta_jar  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}/commons-logging.jar      commons-logging.jar
    
) > $C_FIFO 2>&1
