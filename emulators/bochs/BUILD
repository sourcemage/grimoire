OPTS="--with-x11                        \
      --enable-cdrom=yes                \
      --enable-pci                      \
      --enable-usb                      \
      --enable-cpu-level=6              \
      --enable-x86-64                   \
      --enable-fpu                      \
      --enable-3dnow                    \
      --enable-disasm                   \
      --enable-idle-hack                \
      --enable-all-optimizations        \
      --enable-repeat-speedups          \
      --enable-plugins                  \
      --enable-pnic                     \
      --enable-ne2000                   \
      --disable-docbook                 \
      $RFB $SB16 $TERM $SMP $IPS        \
      $BOCHS_OPTS                       \
      $OPTS"                            &&

case "$HOST" in
  (*-musl)
    OPTS+=' lt_cv_deplibs_check_method=pass_all' ;;
esac &&

CFLAGS="$CFLAGS" CXXFLAGS="$CFLAGS" default_build
