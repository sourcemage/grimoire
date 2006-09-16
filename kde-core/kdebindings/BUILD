sedit  's/$(dir @qt_includes@)/\/usr/'  python/Makefile.am  &&

OPTS="--with-smoke=kde  \
      KDEDIRS=$INSTALL_ROOT/usr  \
      $OPTS"            &&

cd $SOURCE_DIRECTORY &&
./configure &&

cd $SOURCE_DIRECTORY/smoke/qt &&
make

cd $SOURCE_DIRECTORY &&
make TMAKEPATH=/usr/share/tmake/lib/linux-g++

