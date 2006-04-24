  sedit  's/^so:/& all/'  Makefile  &&

  make  MYCFLAGS="$CFLAGS"  MYLDFLAGS="$LDFLAGS -Wl,-E"  \
        LOADLIB="-DUSE_DLOPEN=1"  DLLIB="-ldl"  all  so 
