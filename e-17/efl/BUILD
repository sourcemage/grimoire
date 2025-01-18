disable_evas_loaders= &&
if ! is_depends_enabled "$SPELL" libwebp; then
  disable_evas_loaders+=,webp
fi &&
if ! is_depends_enabled "$SPELL" tiff; then
  disable_evas_loaders+=,tiff
fi &&
if ! is_depends_enabled "$SPELL" openjpeg; then
  disable_evas_loaders+=,jp2k
fi &&
if ! is_depends_enabled "$SPELL" libavif; then
  disable_evas_loaders+=,avif
fi &&
if ! is_depends_enabled "$SPELL" libheif; then
  disable_evas_loaders+=,heif
fi &&
if ! is_depends_enabled "$SPELL" libjxl; then
  disable_evas_loaders+=,jxl
fi &&
if ! is_depends_enabled "$SPELL" rlottie; then
  disable_evas_loaders+=,json
fi &&
if ! is_depends_enabled "$SPELL" librsvg2; then
  disable_evas_loaders+=,rsvg
fi &&
OPTS+=" evas-loaders-disabler=${disable_evas_loaders#,}" &&
CFLAGS+=' -D_LARGEFILE64_SOURCE' &&
default_build
