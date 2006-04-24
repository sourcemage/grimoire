message "${MESSAGE_COLOR}Chosen tools: $ALSATOOLS"
message "${DEFAULT_COLOR}"

for ALSATOOL in $ALSATOOLS
do

  if  [  "$ALSATOOL"  ==  "seq"  ]; then
    cd $SOURCE_DIRECTORY/$ALSATOOL/sbiload
  else
    cd $SOURCE_DIRECTORY/$ALSATOOL
  fi

  message "${MESSAGE_COLOR}Tool $ALSATOOL is being built ..."
  message "${DEFAULT_COLOR}"

  default_build

done
