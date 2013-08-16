if [[ $GNUPG_STATIC == y ]]; then
  LDFLAGS="-static -s $LDFLAGS"
fi &&

# gnupg doesn't play nice with -O3
CFLAGS=${CFLAGS//-O3/-O2} &&

default_build
