if [[ $JACKDMP_VCS != y ]]
then
  cd  "$SOURCE_DIRECTORY/${SPELL}_$VERSION/src/linux"  &&
  make
else
  cd  "$SOURCE_DIRECTORY"                            &&
  scons  $JACKDMP_EXAMPLES  $JACKDMP_MIMIC  $OPTS    \
         BUILD_TESTS=no  PREFIX="$INSTALL_ROOT/usr"
fi
