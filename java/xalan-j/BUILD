. $SECTION_DIRECTORY/java-functions
  
set_ant_env  &&
  
export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar:${ANT_HOME}/lib/optional.jar:${SM_JAKARTA_HOME}/lib/servlet.jar"
export ANT_JAR=$ANT_HOME/bin/ant.jar
export PARSER_JAR=${SM_JAKARTA_HOME}/lib/xercesImpl.jar
export XML_APIS_JAR=${SM_JAKARTA_HOME}/lib/xml-apis.jar
  
mv  build.sh build.sh.winni  &&
tr -s '\r' '\n' < build.sh.winni > build.sh  &&
chmod a+x build.sh  &&
./build.sh dist
