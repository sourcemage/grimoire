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

if [[ $ALSA_TOOLS_BRANCH == scm ]]; then
  OPTS="--prefix=${INSTALL_ROOT}/usr \
    --sysconfdir=${INSTALL_ROOT}/etc \
 --localstatedir=${INSTALL_ROOT}/var \
        --mandir=${INSTALL_ROOT}/usr/share/man \
       --infodir=${INSTALL_ROOT}/usr/share/info \
                 $OPTS" &&
  ./gitcompile $OPTS
else
  default_build
fi

done
