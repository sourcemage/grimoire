#
# Setup ANT_HOME if we haven't relogged since installing ant
#
if  [  -z  $ANT_HOME  ];  then
  if  [  -f  $TRACK_ROOT/etc/profile.d/ant.sh  ];  then
    .  $TRACK_ROOT/etc/profile.d/ant.sh
  else
    #
    # ant must not be installed
    #
    message  "${PROBLEM_COLOR}The package ${SPELL_COLOR}ant${DEFAULT_COLOR}"  \
             "${PROBLEM_COLOR} is not installed.${DEFAULT_COLOR}"             &&
    return  1
  fi
fi  &&

# TODO define arch and windowing system
# possible values are in ./build
ws=gtk                                                               &&
if uname -m | grep -q 'i.\+86'; then
  arch=x86
fi                                                                   &&
./build -os linux -ws "$ws" -arch "$arch"                            &&
echo '/usr/share/eclipse/eclipse -data ~/workspace' > eclipse-script &&
chmod 755 eclipse-script

