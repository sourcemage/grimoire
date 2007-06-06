persistent_add  SOURCE_LIB                           &&
make_single                                          &&
local config=$(<$SCRIPT_DIRECTORY/atlas-nog77.config) &&
if [[ "${SMGL_COMPAT_ARCHS[1]}" == alpha ]]; then
  config=$(<$SCRIPT_DIRECTORY/atlas-alpha.config) &&
  # Tricky: The question may come even if generic chosen,
  # when cpu is ev5/6/7 nevertheless!
  if [[ "${SMGL_COMPAT_ARCHS[3]}" =~ ^ev[567] ]]; then
    config=$(sed 's/EV5GEMM/y/' <<< "$config")
  else # Assume that question is not posed.
    config=$(sed '/EV5GEMM/d' <<< "$config")
  fi
fi &&
if is_depends_enabled $SPELL fortran; then
  config=$(sed 's/FORTRAN/1\ngfortran/' <<< "$config")
else
  config=$(sed 's/FORTRAN/0/' <<< "$config")
fi &&
echo "$config" | make      &&
ARCH=`ls -1 Make.Linux* | sed -e 's/Make.//'`        &&
make  install  arch=$ARCH                            &&
SOURCE_LIB=$SOURCE_DIRECTORY/lib/$ARCH
