OPTS="--enable-fhs                    \
      $SAMBA4                         \
      $OPTS"                          &&

if [[ "$SAMBA4_BRANCH"  ==  "scm" ]]; then
  cd  $SOURCE_DIRECTORY/source4  &&
  make_single
fi &&

default_build  &&
make_normal
