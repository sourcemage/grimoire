if  [  "$GKRELLM_V_ALSA"  ==  "y"  ];  then
  GKRELLM_V_PARAMETERS=enable_alsa=1
fi  &&

if [ "$GKRELLM_V_I18N" = "y" ];  then
  make  $GKRELLM_V_PARAMETERS  enable_nls=1
else
  make  $GKRELLM_V_PARAMETERS
fi
