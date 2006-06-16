# This kludge is required because of a widely known bug in 
# dvlib, which has been fixed but not released and which
# causes kino to segfault.  In the next release the need for
# this should go away, but in the meantime it is necessary
# to work around, as documented here:
# http://www.schirmacher.de/cgi-bin/dcforum/dcboard.cgi?az=show_thread&forum=DCForumID1&om=104&omm=3

if  [ "$(echo $CFLAGS |grep '\-mmmx')" ]; then
  patch  -p1  <  $SCRIPT_DIRECTORY/libdv-mxx.patch
else
  patch  -p1  <  $SCRIPT_DIRECTORY/libdv-no-mxx.patch
fi  &&

export CFLAGS="$CFLAGS -O3"      && # fix compile issues
default_build
