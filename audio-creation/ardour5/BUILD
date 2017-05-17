OPTS="--noconfirm \
      --configdir=$INSTALL_ROOT/etc \
      --optimize \
      --with-backends=$(echo "$ARDOUR4_AUDIO" | tr ' ' ,) \
      $ARDOUR4_OPTS \
      $OPTS" &&
# C++11 features used in glibmm headers.
# Should one fix it there? Globally?!
CXXFLAGS="$CXXFLAGS -std=c++11" &&
waf_build
