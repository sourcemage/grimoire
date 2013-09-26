if [[ $FLUXBOX_BRANCH == scm ]]; then
  ./autogen.sh
fi &&

if is_depends_enabled $SPELL fribidi && is_depends_enabled fribidi glib2; then
  CXXFLAGS="-I$INSTALL_ROOT/usr/include/glib-2.0 \
            -I$INSTALL_ROOT/usr/lib/glib-2.0/include \
            $CXXFLAGS"
fi &&

OPTS="$FLUXBOX_OPTS $OPTS" &&

default_build
