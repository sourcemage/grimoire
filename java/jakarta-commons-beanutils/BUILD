(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env		&&

  export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar" &&

  # create build.properties
  cat > $SOURCE_DIRECTORY/build.properties <<EOF
commons-collections.home=${SM_JAKARTA_HOME}/commons-collections
commons-collections.jar=\${commons-collections.home}/commons-collections.jar
commons-logging.home=$SM_JAKARTA_HOME/commons-logging
commons-logging.jar=\${commons-logging.home}/commons-logging.jar
junit.home=${SM_IBM_HOME}/junit
junit.jar=\${junit.home}/junit.jar
EOF

  ant  dist		&&

  prepare_install 	&&

  extract_jakarta_src   ${PKG_SUBPRJ}-${PKG_NAME} ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}    $SOURCE_DIRECTORY	&&
  register_jakarta_jar  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}/dist/commons-beanutils.jar   commons-beanutils.jar
    
) > $C_FIFO 2>&1
