# Force a specific C standard to avoid build failures with newer compilers
case "$(${CC-gcc} --help)" in
  (*\ -std=*) CFLAGS+=' -std=gnu99';;
esac &&

DEFINES='-DACORN_FTYPE_NFS -DWILD_STOP_AT_DIR -DLARGE_FILE_SUPPORT \
         -DUNICODE_SUPPORT -DUNICODE_WCHAR -DUTF8_MAYBE_NATIVE -DNO_LCHMOD \
         -DDATE_FORMAT=DF_YMD -DNOMEMCPY -DNO_WORKING_ISPRINT' &&

BZIP2='-DUSE_BZIP2' &&

sedit "s/-O /$CFLAGS /;s|)/man|)/share/man|" unix/Makefile &&

if is_depends_enabled $SPELL bzip2; then
  make -f unix/Makefile \
    D_USE_BZ2=-DUSE_BZIP2 L_BZ2=-lbz2 \
    LF2="$LDFLAGS" CF="$CFLAGS $CPPFLAGS -I. $DEFINES $BZIP2" \
    unzips
else
  make -f unix/Makefile \
    LF2="$LDFLAGS" CF="$CFLAGS $CPPFLAGS -I. $DEFINES" \
    unzips
fi
