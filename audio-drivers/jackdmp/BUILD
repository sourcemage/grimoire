#
# Account for packaging differences between the stable and devel version
#
local  _src  &&

#
# Funny stuff needed because the source is a badly built zip archive
#
if [[ $JACKDMP_VCS != y ]]
then
  cd  "$SOURCE_DIRECTORY/${SPELL}_$VERSION"  &&
  _src="src/"
fi  &&

cd  ${_src}linux  &&
make
