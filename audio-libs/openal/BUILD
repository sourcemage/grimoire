if [[ $OPENAL_OSS == n ]]; then
    OPTS="$OPTS --disable-linux"
else
    OPTS="$OPTS --enable-linux"
fi &&
if [[ $OPENAL_VERSION == snapshot ]]; then
  cd linux
elif [[ $OPENAL_VERSION == scm ]]; then
  cd OpenAL-Sample
else
  make_single
fi  &&
default_build
