if is_depends_enabled $SPELL $(get_spell_provider $SPELL JAVA); then
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
  fi
  #
  # End JAVA_HOME setup
  #
fi &&
OPTS+=' --disable-static' &&
default_build
