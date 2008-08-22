#
# Setup ANT_HOME
#
if  [  -f  $INSTALL_ROOT/etc/profile.d/ant.sh  ];  then
  .  $INSTALL_ROOT/etc/profile.d/ant.sh
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
if  [  -f  $INSTALL_ROOT/etc/profile.d/java.sh  ];  then
  .  $INSTALL_ROOT/etc/profile.d/java.sh
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
case "${SMGL_COMPAT_ARCHS[1]}" in
  ia32) arch=x86 ;;
  x86_64) arch=x86_64 ;;
  ppc) arch=ppc ;;
esac &&

persistent_add ws                                                    &&
persistent_add arch                                                  &&
./build -os linux -ws "$ws" -arch "$arch"    &&
echo '/usr/share/eclipse/eclipse -data ~/workspace' > eclipse-script &&
chmod 755 eclipse-script
