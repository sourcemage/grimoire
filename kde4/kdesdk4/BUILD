# replace @ with : for optional dependency flags
OPTS=${OPTS//@/:} &&

if  [[  "$KDESDK_SUBVERSION"  ==  "y"  ]];  then
  OPTS="-DWITH_SVN:BOOL=on $OPTS"
else
  OPTS="-DWITH_SVN:BOOL=off $OPTS"
fi &&

default_build
