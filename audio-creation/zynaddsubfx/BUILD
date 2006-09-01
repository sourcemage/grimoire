# Build standalone synth
if [[ "$BUILD_MODE" != "DSSI plugin" ]]; then
  cd src  &&
  make    &&
  cd ..
fi  &&

# Build DSSI plugin
if [[ "$BUILD_MODE" != "Standalone synth" ]]; then
  cd src_dssi  &&
  make         &&
  cd ..
fi
