persistent_add  SOURCE_LIB                           &&
make_single                                          &&
local config=$(<$SCRIPT_DIRECTORY/atlas-nog77.config) &&
if is_depends_enabled $SPELL fortran; then
  config=$(sed 's/0$/\ngfortran/' <<< "$config")
fi &&
echo "$config" | make      &&
ARCH=`ls -1 Make.Linux* | sed -e 's/Make.//'`        &&
make  install  arch=$ARCH                            &&
SOURCE_LIB=$SOURCE_DIRECTORY/lib/$ARCH
