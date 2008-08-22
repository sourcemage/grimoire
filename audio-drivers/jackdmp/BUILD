if [[ $JACKDMP_VCS != y ]]
then
  cd  "$SOURCE_DIRECTORY/${SPELL}_$VERSION/src/linux"  &&
  make_single  &&
  make         &&
  make_normal
else
  cd  "$SOURCE_DIRECTORY"  &&
  scons  PREFIX="/usr"  DESTDIR="$INSTALL_ROOT"  BUILD_TESTS=no  \
         $JACKDMP_EXAMPLES  $OPTS
fi
