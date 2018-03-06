PREFIX=$INSTALL_ROOT/usr &&
for API in $DRM_API;do
  OPTS+=" $API=true"
done &&
# exclude all others
for EXC in $DRM_ALL;do
  if ! list_find "$DRM_API" $EXC;then
     OPTS+=" $EXC=false"
  fi
done &&
default_build
