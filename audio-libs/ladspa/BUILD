if [ "$LADSPA_SDK" == "y" ]; then
  cd $SOURCE_DIRECTORY/src  &&
  make CFLAGS="\$(INCLUDES) $CFLAGS" LDFLAGS="$LDFLAGS -Wl,--no-as-needed"
else
   true
fi
