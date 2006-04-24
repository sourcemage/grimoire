(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env			&&

  # ant test 
#  export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar"

  # create build.properties
#  cat > $SOURCE_DIRECTORY/build.properties <<EOF
#junit.jar=${SM_IBM_HOME}/lib/junit.jar
#EOF

  ant  dist	&&

  prepare_install &&

  extract_jakarta_src   ${PKG_SUBPRJ}-${PKG_NAME} ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}    $SOURCE_DIRECTORY &&
  register_jakarta_jar  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}/dist/commons-fileupload-1.0-dev.jar  commons-fileupload.jar
  
) > $C_FIFO 2>&1
