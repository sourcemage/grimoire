if [ -f /etc/profile.d/java.sh ]; then
  . /etc/profile.d/java.sh
fi                                      &&

. $SECTION_DIRECTORY/java-functions   &&
  
set_java_env                            &&
  
if  list_find  "$OPTS"  "--with-antlr";  then
  CLASSPATH="$INSTALL_ROOT/usr/share/antlr-$(installed_version antlr)/antlr.jar:$CLASSPATH"
fi                                      &&

# fix bug #3230
if  spell_ok junit;  then
  CLASSPATH="$INSTALL_ROOT/usr/lib/java/ibm-dist/junit/junit-$(installed_version junit).jar:$CLASSPATH"
fi                                      &&

export CLASSPATH  &&
./build.sh -Ddist.dir=antbuild dist  &&
export -n CLASSPATH
