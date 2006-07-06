OPTS="--disable-static  --disable-debug --disable-trace $OPTS"  &&
  case $EXO_RTP in
    ccrtp) OPTS="--enable-ucl $OPTS"
      ;;

    ortp)  OPTS="--enable-ortp $OPTS"
      ;;

    none)  OPTS="--disable-josua $OPTS"
      ;;
  esac            &&
message opt=$OPTS &&
default_build
