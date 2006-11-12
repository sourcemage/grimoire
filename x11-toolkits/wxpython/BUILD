local contrib  &&
persistent_read  wxgtk  WX_CONTRIB  WX_CONTRIB  &&
message gtk=$WX_DEV             &&
message contrib=$WX_CONTRIB     &&
PYOPTS='MONOLITHIC=0 UNICODE=1' &&
for COMPONENT in $WX_CONTRIB; do
  PYOPTS="$PYOPTS BUILD_$(echo $COMPONENT | tr '[:lower:]' '[:upper:]')=1"
done  &&
#if echo $OPTS | grep -q with-swig; then PYOPTS="$PYOPTS USE_SWIG=1"; fi &&
if [[ $WX_DEV == y ]];then
  PYOPTS=${PYOPTS//BUILD_ANIMATE=1/}
else
  PYOPTS=${PYOPTS//BUILD_FOLDBAR=1/}
fi                             &&
PYOPTS=${PYOPTS//BUILD_FL=1/}  &&
# suppress undesired options
for contrib in ANIMATE GIZMOS STC;do
  if [[ $PYOPTS != "*$contrib*" ]];then
    PYOPTS="$PYOPTS BUILD_$contrib=0"
  fi 
done &&
persistent_add PYOPTS          &&
cd wxPython &&
python setup.py $PYOPTS build
