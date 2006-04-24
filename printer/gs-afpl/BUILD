[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"

sedit  "s:CFLAGS_STANDARD=@OPT_CFLAGS@:CFLAGS_STANDARD=$CFLAGS:g"        Makefile.in  &&
sedit  "s:CFLAGS_PROFILE=-pg @OPT_CFLAGS@:CFLAGS_PROFILE=-pg $CFLAGS:g"  Makefile.in  &&

make_single    &&
default_build  &&

if  [  "$GS_AFPL_LIBGS"  =  "y"  ];  then
  make  so
fi
