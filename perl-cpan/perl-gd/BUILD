local GD_OPTIONS="GIF,ANIMGIF" &&

if is_depends_enabled gd $(get_spell_provider gd JPEG) &&
   is_depends_enabled $SPELL $(get_spell_provider $SPELL JPEG); then
  GD_OPTIONS+=",JPEG"
fi &&

if is_depends_enabled gd freetype2 && is_depends_enabled $SPELL freetype2; then
  GD_OPTIONS+=",FT"
fi &&

if is_depends_enabled gd libpng && is_depends_enabled $SPELL libpng; then
  GD_OPTIONS+=",PNG"
fi &&

if is_depends_enabled gd libxpm && is_depends_enabled $SPELL libxpm; then
  GD_OPTIONS+=",XPM"
fi &&

perl Makefile.PL -options="$GD_OPTIONS" --lib_gd_path "${INSTALL_ROOT}/usr/lib"  &&
make
