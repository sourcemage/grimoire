# If we got -march=… in CFLAGS, the configure script assumes we
# got everything arch-specific set up, including PICyness. Without
# prescribed architecture, it would detect one and add PIC flags.
if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]]; then
  CFLAGS="$CFLAGS -DPIC -fPIC"
fi &&
default_build
