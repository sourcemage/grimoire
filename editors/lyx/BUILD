CFLAGS=${CFLAGS/-O3/-O2}     &&
CXXFLAGS=${CXXFLAGS/-O3/-O2} &&
if [  "${LYX_GUI}" == "xforms"  ]
  then 
     OPTS="${OPTS} --with-frontend=xforms"
  else 
     OPTS="${OPTS} --with-frontend=qt4   \
                   --with-qt-libraries=/usr/lib/qt4"  &&
     PATH=$QTDIR/bin/qt4:$PATH
fi
default_build
