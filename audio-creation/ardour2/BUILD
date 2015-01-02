PKG_CONFIG_PATH="$INSTALL_ROOT/opt/aubio03/lib/pkgconfig:$PKG_CONFIG_PATH" \
scons -j$MAKE_NJOBS "PREFIX=$INSTALL_ROOT/usr" $OPTS  \
       SYSLIBS=1                         \
       $ARDOUR2_SURFACES                 \
       $ARDOUR2_WIIMOTE                  \
       $ARDOUR2_OLDFONTS                 \
       $ARDOUR2_FFT_ANALYSIS
