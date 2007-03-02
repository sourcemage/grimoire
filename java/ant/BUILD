if [ -f /etc/profile.d/java.sh ]; then
  . /etc/profile.d/java.sh
fi                                      &&

. $SECTION_DIRECTORY/java-functions   &&
  
set_java_env                            &&
  
if  list_find  "$OPTS"  "--with-antlr";  then
  export CLASSPATH="${SM_OTH_HOME}/lib/antlr.jar:$CLASSPATH"
fi                                      &&

./build.sh -Ddist.dir=antbuild dist
