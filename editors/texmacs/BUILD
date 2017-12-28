LDFLAGS="$LDFLAGS -lz" &&
if is_depends_enabled "$SPELL" qtbase; then
  qt5_cmake_build "$INSTALL_ROOT/usr"
else
  qt4_cmake_build "$INSTALL_ROOT/usr"
fi
