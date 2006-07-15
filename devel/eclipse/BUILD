#
# Setup ANT_HOME
#
if  [  -f  $TRACK_ROOT/etc/profile.d/ant.sh  ];  then
  .  $TRACK_ROOT/etc/profile.d/ant.sh
else
  #
  # ant must not be installed
  #
  message  "${PROBLEM_COLOR}The package ${SPELL_COLOR}ant${DEFAULT_COLOR}"  \
           "${PROBLEM_COLOR} is not installed.${DEFAULT_COLOR}"             &&
  return  1
fi  &&
#
# End ANT_HOME setup
#

#
# Setup JAVA_HOME
#
if  [  -f  $TRACK_ROOT/etc/profile.d/java.sh  ];  then
  .  $TRACK_ROOT/etc/profile.d/java.sh
else
  #
  # JAVA must not be installed
  #
  message  "${PROBLEM_COLOR}The provider ${SPELL_COLOR}JAVA${DEFAULT_COLOR}"  \
           "${PROBLEM_COLOR} is not installed.${DEFAULT_COLOR}"               &&
  return  1
fi  &&
#
# End JAVA_HOME setup
#

# TODO define arch and windowing system
# possible values are in ./build
ws=gtk                                                               &&
if uname -m | grep -q 'i.\+86'; then
  arch=x86
fi                                                                   &&
./build -os linux -ws "$ws" -arch "$arch"  -java5home $JAVA_HOME     &&
echo '/usr/share/eclipse/eclipse -data ~/workspace' > eclipse-script &&
chmod 755 eclipse-script

