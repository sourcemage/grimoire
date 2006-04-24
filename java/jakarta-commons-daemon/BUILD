(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env			&&

  # create build.properties
  cat > $SOURCE_DIRECTORY/build.properties <<EOF
junit.home=${SM_IBM_HOME}/junit
junit.jar=\${junit.home}/junit.jar
EOF

  ant  dist	&&

  prepare_install &&

  extract_jakarta_src   ${PKG_SUBPRJ}-${PKG_NAME} ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}    $SOURCE_DIRECTORY	&&
  register_jakarta_jar  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}/dist/commons-daemon.jar  commons-daemon.jar
  
) > $C_FIFO 2>&1
