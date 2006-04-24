(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env			&&

  # create build.properties
  cat > $SOURCE_DIRECTORY/${PKG_SUBPRJ}-${PKG_NAME}/build.properties <<EOF
base.path=${SM_JAKARTA_HOME}
commons-collections.home=\${base.path}/commons-collections
commons-collections.jar=\${commons-collections.home}/commons-collections.jar
junit.jar=${SM_IBM_HOME}/lib/junit.jar
EOF

  cd  ${PKG_SUBPRJ}-${PKG_NAME} &&
  cp  LICENSE.txt ../LICENSE 	&&
  ant  dist			&&

  prepare_install 		&&

  extract_jakarta_src   ${PKG_SUBPRJ}-${PKG_NAME} ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}    $SOURCE_DIRECTORY/${PKG_SUBPRJ}-${PKG_NAME}	&&
  register_jakarta_jar  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}/dist/commons-lang-2.0-dev.jar  commons-lang.jar
  
) > $C_FIFO 2>&1
