#OPTS="ASIO=False  COREAUDIO=False  $ZZUB_BUZZ2ZUB  $ZZUB_BMPCCM  \
OPTS="ASIO=False  COREAUDIO=False  $ZZUB_BUZZ2ZUB   \
      $ZZUB_LUNAR  $ZZUB_OSS  $ZZUB_MP3  $ZZUB_SSE  \
      $ZZUB_SSE2  $OPTS"                            &&

if [[ $ZZUB_LUNAR == 'LUNAR=True' ]]
then
  OPTS="LUNARTARGET=gcc  $OPTS"
fi  &&

scons  configure  $OPTS  PREFIX=/usr  DESTDIR="$INSTALL_ROOT"  &&
scons
