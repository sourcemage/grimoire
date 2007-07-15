OPTS="$CELESTIA_XINERAMA                                            \
      $CELESTIA_FINAL                                               \
      --with-gconf-schema-file-dir=$INSTALL_ROOT/etc/gconf/schemas  \
      --with-included-gettext                                       \
      --disable-debug                                               \
      $OPTS"                                                        &&
#
# Little mungery because celestia configure strangely fails to expand
# ${prefix} for the data root
#
OPTS+=" --datarootdir=/usr/share --datadir=/usr/share " &&

default_build
