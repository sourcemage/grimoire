# speed up up build process by removing unnecessary examples
rm -r examples
rm -r extensions/nsplugin/examples
#rm -r extensions/xt/examples
rm -r tools/designer/examples
#rm -r tools/designer/tutorials
#rm -r tools/linguist/tutorial
#rm -r tools
rm -r tutorial

# add better optimisation flags
sedit "s#-O2#$CFLAGS#" mkspecs/linux-g++/qmake.conf &&
sedit "s#-O2#$CFLAGS#" mkspecs/linux-cxx/qmake.conf &&

export QTDIR=$SOURCE_DIRECTORY  &&
export LD_LIBRARY_PATH=$SOURCE_DIRECTORY/lib:$LD_LIBRARY_PATH &&

#  if  spell_ok  postgresql;  then
#    cd  $SOURCE_DIRECTORY  &&
#   tar  -zxpf  /var/spool/sorcery/postgresql-`installed_version postgresql`.tar.gz  &&
#    cd  postgresql-`installed_version postgresql`  &&
#    ./configure  &&
#    cd  $SOURCE_DIRECTORY
#  fi  &&

OPTS="$OPTS       \
      $QT_IPV6    \
      $QT_DEBUG   \
      $QT_THREAD  \
      $QT_NIS     \
      $QT_XRAMA"  &&

echo  "yes"  |  ./configure                                                \
                             -prefix ${INSTALL_ROOT}/usr/lib/qt            \
                             -bindir ${INSTALL_ROOT}/usr/bin               \
                             -libdir ${INSTALL_ROOT}/usr/lib               \
                             -docdir ${INSTALL_ROOT}/usr/share/doc/qt-x11  \
                             -headerdir ${INSTALL_ROOT}/usr/include/qt     \
                             -datadir ${INSTALL_ROOT}/usr/share/qt         \
                             -qt-gif                                       \
                             -xft                                          \
                             -stl                                          \
                             -dlopen-opengl                                \
                             $OPTS                                         &&

make  symlinks  sub-src sub-tools
