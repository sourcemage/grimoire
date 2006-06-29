. $SECTION_DIRECTORY/java-functions
  
set_ant_env  &&
export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar:${SM_SUN_HOME}/lib/jdmkrt.jar" &&
cd build   &&
chmod a+x build-regexp.sh   &&
./build-regexp.sh jar   &&

rm  $SOURCE_DIRECTORY/jakarta-regexp-1.2.jar  &&
mv  $SOURCE_DIRECTORY/bin/jakarta-regexp-1.2.jar  $SOURCE_DIRECTORY/jakarta-regexp-1.2.jar  &&
rm  -rf $SOURCE_DIRECTORY/bin
