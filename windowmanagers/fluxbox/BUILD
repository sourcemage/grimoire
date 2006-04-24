export CPPFLAGS=-I/usr/include/freetype2  &&

if  [  "$CVS"  ==  "y"  ];  then
  ./autogen.sh
fi  &&

if  [  "$NLS"  ==  "n"  ];  then
  OPTS="$OPTS --disable-nls"
fi   &&

default_build
