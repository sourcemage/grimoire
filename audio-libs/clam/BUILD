# fix amd64 warnings
patch -p1 < $SCRIPT_DIRECTORY/assert64.patch 

export OLDQTDIR=$QTDIR &&
unset QTDIR &&
cd scons/libs &&
sed -e s/qt3/qt/ -i SConstruct &&
scons $OPTS prefix=$INSTALL_ROOT/usr configure &&
scons $OPTS prefix=$INSTALL_ROOT/usr 
