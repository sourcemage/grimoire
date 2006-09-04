#no autotools yet... constructing the build
# choice: gnu, gnu-oss, gnu-alsa
patch -Np1 < ${SCRIPT_DIRECTORY}/dermixd-1.1.0-beta2.frontend.patch &&
sedit 's/-pedantic-errors//' Makefile &&
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
make $DMD_BUILD
