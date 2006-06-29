. $SECTION_DIRECTORY/java-functions
  
set_ant_env  &&

export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar" &&

# create build.properties
cat > $SOURCE_DIRECTORY/${PKG_SUBPRJ}-${PKG_NAME}/build.properties <<EOF
commons.home=${SM_JAKARTA_HOME}/
sandbox.home=${SM_JAKARTA_HOME}/commons-sandbox
jaxp.home=${SM_SUN_HOME}/java_xml_pack/jaxp-1.2_01
junit.home=${SM_IBM_HOME}/junit
jmx.home=${SM_SUN_HOME}/jmx
beanutils.home=\${commons.home}/commons-beanutils
collections.home=\${commons.home}/commons-collections
digester.home=\${commons.home}/commons-digester
logging.home=\${commons.home}/commons-logging
commons-beanutils.jar=\${beanutils.home}/dist/commons-beanutils.jar
commons-collections.jar=\${collections.home}/commons-collections.jar
commons-digester.jar=\${digester.home}/dist/commons-digester.jar
commons-logging.jar=\${logging.home}/commons-logging.jar
jmx.jar=\${jmx.home}/lib/jmxri.jar
jmxtools.jar=\${jmx.home}/lib/jmxtools.jar
jaxp.jaxp.jar=\${jaxp.home}/jaxp-api.jar
jaxp.parser.jar=${SM_JAKARTA_HOME}/lib/crimson.jar
jaxp.xalan.jar=${SM_JAKARTA_HOME}/lib/xalan.jar
junit.jar=\${junit.home}/junit.jar
EOF
  
cd  ${PKG_SUBPRJ}-${PKG_NAME}  &&
cp  LICENSE.txt ../LICENSE  &&
  
ant  dist
