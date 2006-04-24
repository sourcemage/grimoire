CFLAGS=${CFLAGS/-O3/-O2}     &&
CXXFLAGS=${CXXFLAGS/-O3/-O2} &&
if [  "${LYX_GUI}" == "xforms"  ]
then OPTS="${OPTS} --with-frontend=xforms"
else OPTS="${OPTS} --with-frontend=qt                  \
                   --with-qt-includes=/usr/include/qt  \
                   --with-qt-libraries=/usr/lib/qt"
fi
default_build
