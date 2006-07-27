unset QTDIR &&
cd scons/libs &&
sed -e s/qt3/qt/ -i SConstruct &&
echo $OPTS
scons $OPTS prefix=$INSTALL_ROOT/usr configure &&
scons $OPTS prefix=$INSTALL_ROOT/usr 
