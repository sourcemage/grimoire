#no autotools yet... constructing the build
# choice: gnu, gnu-oss, gnu-alsa
if list_find "$OPTS" --enable-alsa
then
  if [[ "$DMD_OSS" == y ]]
  then
    DMD_BUILD=gnu
  else
    DMD_BUILD=gnu-alsa
  fi
else
  DMD_BUILD=gnu-oss
fi &&
MAKE_OPT= &&
if list_find "$OPTS" --enable-sndfile; then
  MAKE_OPT="$MAKE_OPT SNDFILE=yes"
fi &&
make $MAKE_OPT $DMD_BUILD
