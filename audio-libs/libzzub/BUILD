OPTS="ASIO=False COREAUDIO=False $ZZUB_OPTS $OPTS" &&

if list_find "$ZZUB_OPTS" "LUNAR=True"
then
  OPTS="LUNARTARGET=gcc $OPTS"
fi &&

scons configure $OPTS PREFIX=/usr DESTDIR="$INSTALL_ROOT" &&
scons 
