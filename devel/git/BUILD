GIT_MAKE_OPTS="$GIT_MAKE_OPTS $OPTS"  &&

make  HOME="${TRACK_ROOT}/usr"  $GIT_MAKE_OPTS  &&

if  [[  $GIT_DOCS  ==  "y"  ]];  then
  make  -C  Documentation
fi
