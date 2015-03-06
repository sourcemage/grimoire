CFLAGS="${CFLAGS//-ffast-math}"
CXXFLAGS="${CXXFLAGS//-ffast-math}"
LDFLAGS="${LDFLAGS//-Wl,--as-needed}"

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

# FIXME: Fonts should be installed to /usr/share/fonts
# FIXME: Documentation should be installed to /usr/share/doc
./configure --prefix="$INSTALL_ROOT"/usr/lib/aplus       \
            --bindir="$INSTALL_ROOT"/usr/bin             \
            --libdir="$INSTALL_ROOT"/usr/lib             \
        --includedir="$INSTALL_ROOT"/usr/include         \
        --sysconfdir="$INSTALL_ROOT"/etc                 \
     --localstatedir="$INSTALL_ROOT"/var                 \
     $OPTS &&
make
