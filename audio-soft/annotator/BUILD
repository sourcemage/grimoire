# add link to /usr/bin/qt4 so annotator can find it
ln -s /usr/bin/qt4 /usr/lib/qt4/bin
export OLDQTDIR=$QTDIR &&
unset QTDIR &&
export QTDIR=/usr/lib/qt4 &&
cd vmqt &&
scons clam_prefix=$INSTALL_ROOT/usr prefix=$INSTALL_ROOT/usr &&
cd $SOURCE_DIRECTORY &&
scons clam_prefix=$INSTALL_ROOT/usr install_prefix=$INSTALL_ROOT/usr
