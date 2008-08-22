make_single
if [[ "$APPK" == "n" ]];
then
  OPTS="appkit=no"
  message "Building StepTalk without AppKit extensions"  &&
  default_build $OPTS
else
  default_build
fi                                                       &&
make_normal
