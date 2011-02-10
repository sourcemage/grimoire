if [ "$LADSPA_SDK" == "y" ]; then
  cd $SOURCE_DIRECTORY/src  &&
  make CFLAGS="\$(INCLUDES) $CFLAGS"
else
   true
fi
