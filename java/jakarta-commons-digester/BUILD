. $SECTION_DIRECTORY/java-functions
  
set_ant_env  &&
  
export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar"

# create build.properties
cat > $SOURCE_DIRECTORY/build.properties <<EOF
jaxp.home=${SM_SUN_HOME}/java_xml_pack/jaxm-1.1_01/lib
jaxp.jaxp.jar=\${jaxp.home}/jaxp-api.jar
jaxp.parser.jar=${SM_JAKARTA_HOME}/lib/xercesImpl.jar
commons-beanutils.home=${SM_JAKARTA_HOME}/commons-beanutils/dist
commons-beanutils.jar=\${commons-beanutils.home}/commons-beanutils.jar
commons-collections.home=${SM_JAKARTA_HOME}/commons-collections
commons-collections.jar=\${commons-collections.home}/commons-collections.jar
commons-logging.home=${SM_JAKARTA_HOME}/commons-logging
commons-logging.jar=\${commons-logging.home}/commons-logging.jar
junit.jar=${SM_IBM_HOME}/lib/junit.jar
EOF

sedit  "s:../LICENSE:LICENSE.txt:"   build.xml && 

ant  dist
