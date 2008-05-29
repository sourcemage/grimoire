if [[ $AESPIPE_STATIC == y ]]; then
  LDFLAGS="-static -s" default_build
else
  default_build
fi &&

make tests
