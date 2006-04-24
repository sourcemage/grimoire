sedit  's/$(dir @qt_includes@)/\/usr/'  python/Makefile.am  &&
aclocal                                                     &&

OPTS="--with-smoke=kde  \
      KDEDIRS=$INSTALL_ROOT/usr  \
      $OPTS"            &&

TMAKEPATH=/usr/share/tmake/lib/linux-g++  \
source  $SECTION_DIRECTORY/KDE_BUILD
