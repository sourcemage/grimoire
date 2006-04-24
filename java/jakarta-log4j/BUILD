(

  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env			&&

  # create build.properties
  cat > $SOURCE_DIRECTORY/build.properties <<EOF
jaxp.jaxp.jar=${SM_SUN_HOME}/java_xml_pack/jaxm-1.1_01/lib/jaxm-api.jar
jaxp.parser.jar=${SM_JAKARTA_HOME}/lib/crimson.jar
javamail.jar=${SM_SUN_HOME}/lib/mail.jar
activation.jar=${SM_SUN_HOME}/lib/activation.jar
jms.jar=${SM_SUN_HOME}/lib/jms.jar
jmx.jar=${SM_SUN_HOME}/lib/jmxri.jar
jmx-extra.jar=${SM_SUN_HOME}/lib/jmxtools.jar
EOF

  export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar:${SM_SUN_HOME}/lib/jdmkrt.jar" &&
  ant init clean javadoc jar 	&&

  cd $SOURCE_DIRECTORY/dist	&&
  mv lib ../			&&
  cd ..				&&
  rm -rf dist			&&

  prepare_install									&&

  extract_jakarta_src   ${PKG_NAME}  ${PKG_NAME}-${VERSION}     $SOURCE_DIRECTORY	&&
  register_jakarta_jar  ${PKG_NAME}-${VERSION}/lib/log4j-1.2.8.jar  log4j.jar
    
) > $C_FIFO 2>&1
