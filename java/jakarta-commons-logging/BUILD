. $SECTION_DIRECTORY/java-functions
  
set_ant_env  &&
export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar" &&
  
# create build.properties
cat > $SOURCE_DIRECTORY/logging/build.properties <<EOF
log4j.jar=${SM_JAKARTA_HOME}/lib/log4j.jar
logkit.jar=${SM_JAKARTA_HOME}/lib/logkit.jar
junit.jar=${SM_IBM_HOME}/lib/junit.jar
EOF

cd logging  &&
cp LICENSE.txt ../LICENSE  &&
ant  dist test
