PREFIX=$INSTALL_ROOT/usr &&
for API in $DRM_API;do
  if [[ "${LIBDRM_BRANCH}" == "scm" ]]; then
    OPTS+=" $API=enabled"
  else
    # remove on next release
    OPTS+=" $API=true"
  fi
done &&
# exclude all others
for EXC in $DRM_ALL;do
  if ! list_find "$DRM_API" $EXC;then
    if [[ "${LIBDRM_BRANCH}" == "scm" ]]; then
     OPTS+=" $EXC=disabled"
    else
    # remove on next release
     OPTS+=" $EXC=false"
    fi
  fi
done &&
default_build
