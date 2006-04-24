if  [  "$CVS"  ==  "y"  ];  then
  cd  lib       &&
  ./autogen.sh
fi  &&

if  [  "$OPENGLUT_GLUT"  =  "y"  ];  then
  OPTS="$OPTS  --replace-glut"
fi  &&

OPTS="$OPTS  --enable-fast"  &&

default_build
