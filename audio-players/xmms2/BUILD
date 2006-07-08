if list_find "$XMMS2_OPTS1" noruby ; then
  list_remove OPTS ruby
fi &&
if list_find "$XMMS2_OPTS1" nopython ; then
  list_remove OPTS python
fi &&
if list_find "$XMMS2_OPTS1" noxmmsclient++ ; then
  list_remove OPTS xmmsclient++
fi &&
if list_find "$XMMS2_OPTS1" noxmmsclient-ecore ; then
  list_remove OPTS xmmsclient-ecore
fi &&
if list_find "$XMMS2_OPTS1" nojava ; then
  list_remove OPTS java
fi &&
cd  $SOURCE_DIRECTORY/xmms*                 &&
scons MANDIR=${INSTALL_ROOT}/usr/share/man  \
      PREFIX=${INSTALL_ROOT}/usr            \
      CCFLAGS="$CFLAGS"                     \
      CXXFLAGS="$CXXFLAGS"                  \
      EXCLUDE="$XMMS2_OPTS $OPTS"           &&
scons MANDIR=${INSTALL_ROOT}/usr/share/man  \
      PREFIX=${INSTALL_ROOT}/usr            \
      CCFLAGS="$CFLAGS"                     \
      CXXFLAGS="$CXXFLAGS"                  \
      EXCLUDE="$XMMS2_OPTS $OPTS"
