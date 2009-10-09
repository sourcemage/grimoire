message "Target list: $QEMU_ARCHS" &&

#
# Disable PIC if building soft MMU targets
# Pentium3/4 or athlon(-xp) breaks on building soft MMU
# generally shrinking march down to pentium-mmx
#
if grep -q softmmu <<< "$QEMU_ARCHS"; then
  # we need to check does 0.10 act the same way
  message "${MESSAGE_COLOR}QEMU 0.9 has a build problem with advanced CFLAGS.${DEFAULT_COLOR}" &&
  message "${MESSAGE_COLOR}Trying to make it work, starting with removal of any sse flags.${DEFAULT_COLOR}" &&
  # sse seems to be bad; -march=pentium -m3dnow worked, though
  list_remove CFLAGS -msse -msse2 -msse3 -mfpmath=sse &&
  if [[ "$CFLAGS" =~ -march=pentium[^[:space:]]+ ]]; then
    message "${MESSAGE_COLOR}Reducing your $BASH_REMATCH to pentium-mmx.${DEFAULT_COLOR}" &&
    list_remove CFLAGS $BASH_REMATCH &&
    CFLAGS="$CFLAGS -march=pentium-mmx"
  fi &&

  # -march=prescott was added after 
  if [[ "$CFLAGS" =~ -march=prescott ]]; then
    message "${MESSAGE_COLOR}Reducing your $BASH_REMATCH to pentium-mmx.${DEFAULT_COLOR}" &&
    list_remove CFLAGS $BASH_REMATCH &&
    CFLAGS="$CFLAGS -march=pentium-mmx"
  fi &&
  if [[ "$CFLAGS" =~ -march=athlon[^[:space:]]* ]]; then
    message "${MESSAGE_COLOR}Reducing your $BASH_REMATCH to k6-3.${DEFAULT_COLOR}" &&
    list_remove CFLAGS $BASH_REMATCH &&
    CFLAGS="$CFLAGS -march=k6-3"
  fi &&
  disable_pic
fi  &&

./configure --prefix="$INSTALL_ROOT/usr" \
       --target-list="$QEMU_ARCHS"       \
                     $OPTS               &&

make
