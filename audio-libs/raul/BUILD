if [[ $RAUL_VCS == y ]]
then
  cd  "$SOURCE_DIRECTORY/raul"
fi  &&

default_build  &&

if  is_depends_enabled  $SPELL  doxygen
then
  make  docs
fi
