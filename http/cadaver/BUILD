case $CADAVER_THREADS in
  none) OPTS="--disable-threads $OPTS"
  ;;
  posix) OPTS="--enable-threads=posix $OPTS"
  ;;
  pth) OPTS="--enable-threads=pth $OPTS"
  ;;
esac &&

OPTS="$CADAVER_OPTS $OPTS" &&

default_build
