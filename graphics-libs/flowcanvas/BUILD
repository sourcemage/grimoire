if [[ $FLOWCANVAS_VCS == y ]]
then
  cd  "$SOURCE_DIRECTORY/flowcanvas"
fi  &&

OPTS="$FLOWCANVAS_ANTIALIAS $OPTS"  default_build  &&

if  is_depends_enabled  $SPELL  doxygen
then
  make  docs
fi
