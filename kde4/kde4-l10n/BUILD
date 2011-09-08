QTDIR=$INSTALL_ROOT/usr                         &&
PATH=$QTDIR/bin/qt4:$PATH                       &&

persistent_add KDE4DIR                          &&
KDE4DIR=$INSTALL_ROOT/usr                  &&

PATH=$KDE4DIR/bin:$PATH                         &&
LD_LIBRARY_PATH=$KDE4DIR/lib:$LD_LIBRARY_PATH   &&
QT_PLUGIN_PATH=$KDE4DIR/lib/kde4/plugins        &&

XDG_DATA_DIRS=$KDE4DIR/share                    &&

cd $SOURCE_DIRECTORY                            &&


local  BUILD_SUBDIRECTORY                       &&

for  BUILD_SUBDIRECTORY  in  $SPELLX*
do
  if  [  -d  $BUILD_SUBDIRECTORY  ]
  then
    message  "${MESSAGE_COLOR}Building $BUILD_SUBDIRECTORY${DEFAULT_COLOR}"  &&
    cd $BUILD_SUBDIRECTORY                                                   &&
    mkdir -p build                                  &&
    cd build                                        &&
    cmake -DCMAKE_INSTALL_PREFIX=$KDE4DIR           \
          -DCMAKE_BUILD_TYPE=$KDE_DEBUG_OPTION      \
          ../                                       &&
    make &&
    cd $SOURCE_DIRECTORY
  fi
done
