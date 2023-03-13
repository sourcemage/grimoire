OPTS="packagekit=false fwupd=false mogwai=false snap=false malcontent=false \
$WEBAPP $FEATURED $CURATED $TESTS $OPTS" &&
if [[ $WEBAPP == "webapps=true" ]]; then
  OPTS+=" $PROPAPP $FOSSAPP"
else
  OPTS+=" hardcoded_proprietary_webapps=false hardcoded_foss_webapps=false"
fi &&
meson_build
