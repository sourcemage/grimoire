if  [  "$LUFS_CARDFS"  =  "y"  ];  then
  OPTS="$OPTS  --enable-cardfs"
fi  &&

if  [  "$LUFS_CEFS"  =  "y"  ];  then
  OPTS="$OPTS  --enable-cefs"
fi  &&

if  [  "$LUFS_SUID"  =  "n"  ];  then
  OPTS="$OPTS  --disable-suid"
fi  &&

if  [  "$LUFS_KERNEL"  =  "y"  ];  then
  OPTS="$OPTS  --disable-kernel-support"
fi  &&

sedit  "s:\-O2:${CFLAGS}:g"  configure  &&
default_build
