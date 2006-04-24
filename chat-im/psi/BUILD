  if [ "$DEVEL" == "y" ]; then
     sed -i -e "s:bin/qmake:bin/qt4/qmake:g" $SOURCE_DIRECTORY/configure &&
     sedit '30i#include <cstdio>' $SOURCE_DIRECTORY/src/tools/trayicon/trayicon_x11.cpp  &&
     sedit '39i#include <cstdio>' $SOURCE_DIRECTORY/src/psiapplication.cpp
  else
  if [ -d /usr/lib/kde3 ];then
    export KDEDIR=/usr/lib/kde3
  fi   
  fi                                                        &&
  export QTDIR=/usr                                         &&
  ./configure --prefix=/usr $OPTS                           &&
  sedit "s/QTDIR)\/include/QTDIR)\/include\/qt/g" Makefile  &&
  make_single     &&
  make            &&
  make_normal
