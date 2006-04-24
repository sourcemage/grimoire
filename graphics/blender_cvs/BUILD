(
  # Setup our environment
  sedit  "s:use_openal = \'false\':use_openal = \'true\':"  SConstruct          &&
  sedit  "s:build_blender_player = \'false\':build_blender_player = \'true\':"  \
                                                            SConstruct          &&
  #This doesn't seem to work...
  #sedit  "s:cxxflags = \[\]:cxxflags = \[$CXXFLAGS\]:"      SConstruct          &&

  # Configure SCons...I'm not sure I like this sytem...
  if    grep  -q  "enable-gameblender"  ${OPTS}
  then  sedit  "s:use_ode = \'false\':use_ode = \'true\':"  SConstruct
  else  sedit  "s:use_gameengine = \'true\':use_gameengine = \'false\':"  SConstruct
  fi  &&

  if    grep  -q  "enable-blenderplugin"  ${OPTS}
  then  sedit  "s:build_blender_plugin = \'false\':build_blender_plugin = \'true\':"  SConstruct
  fi  &&

  scons                  &&
  prepare_install        &&
  cp  blender  /usr/bin

) > $C_FIFO 2>&1
