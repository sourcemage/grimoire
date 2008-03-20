echo doing common ----------------------------------- &&
cd common &&
default_build &&

echo doing unix ----------------------------------- &&
cd ../unix &&
default_build &&

# building Xvnc requires the whole X server be built #8752
if [[ $VNC_SERVER == y ]]; then
  echo doing the server ----------------------------------- &&
  cd xorg-server &&
  OPTS="$OPTS --enable-xorg --disable-xnest --disable-xvfb --disable-dmx" &&
  OPTS="$OPTS --disable-xwin --disable-xephyr --disable-kdrive --disable-xorgcfg" &&
  OPTS="$OPTS --disable-xprint --disable-static  --enable-composite --enable-xtrap" &&
  OPTS="$OPTS --enable-xcsecurity --disable-xevie --disable-dri" &&
  default_build &&
  cd ..
fi &&
cd ..
