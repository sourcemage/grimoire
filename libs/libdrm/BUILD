PREFIX=$INSTALL_ROOT/usr &&
for API in $DRM_API;do
  OPTS+=" $API=enabled"
done &&
# exclude all others
for EXC in $DRM_ALL;do
  if ! list_find "$DRM_API" $EXC;then
    OPTS+=" $EXC=disabled"
  fi
done &&
default_build
