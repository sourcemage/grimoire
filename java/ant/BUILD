if [ -f /etc/profile.d/java.sh ]; then
  . /etc/profile.d/java.sh
fi                                      &&

. $SECTION_DIRECTORY/java-functions   &&
  
set_java_env                            &&
  
if  list_find  "$OPTS"  "--with-antlr";  then
  export CLASSPATH="$INSTALL_ROOT/usr/share/antlr-$(installed_version antlr)/antlr.jar:$CLASSPATH"
fi                                      &&

./build.sh -Ddist.dir=antbuild dist
