if [ -f /etc/profile.d/java.sh ]; then
  . /etc/profile.d/java.sh
fi                                      &&

. $SECTION_DIRECTORY/java-functions   &&

OPTS="--disable-examples  \
      $OPTS"              &&
  
set_java_env  &&

default_build
