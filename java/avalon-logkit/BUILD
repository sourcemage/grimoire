. $SECTION_DIRECTORY/java-functions

set_ant_env  &&

# create ant.properties
cat > $SOURCE_DIRECTORY/ant.properties <<EOF    
java.home=${JAVA_HOME}
EOF

cp ${SM_SUN_HOME}/lib/jms.jar $SOURCE_DIRECTORY/lib/  &&
cp ${SM_JAKARTA_HOME}/lib/servlet.jar $SOURCE_DIRECTORY/lib/  &&
cp ${SM_SUN_HOME}/lib/mail.jar $SOURCE_DIRECTORY/lib/mail.jar  &&
cp ${SM_JAKARTA_HOME}/lib/log4j.jar $SOURCE_DIRECTORY/lib/log4j-1.2.7.jar  &&
cp ${SM_IBM_HOME}/lib/junit.jar $SOURCE_DIRECTORY/lib/junit-3.7.jar   &&
  
export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar" &&
ant clean jar   &&

rm  $SOURCE_DIRECTORY/lib/*  &&
mv  $SOURCE_DIRECTORY/build/lib/logkit.jar  $SOURCE_DIRECTORY/lib/  &&
rm  -rf  $SOURCE_DIRECTORY/build  &&
rm  -rf  $SOURCE_DIRECTORY/old.libraries
