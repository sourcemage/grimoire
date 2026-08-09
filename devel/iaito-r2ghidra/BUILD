cd "$SOURCE_DIRECTORY/src/plugins/r2ghidra" &&
export R2GHIDRA_PLUGDIR="$(radare2 -H R2_LIBR_PLUGINS)" &&
if is_depends_enabled iaito qt6base; then
  qt6_build
else
  qt5_build
fi
