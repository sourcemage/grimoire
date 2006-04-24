  bzcat $SCRIPT_DIRECTORY/glibc-2.2.4-cleanup_region_start.diff.bz2 | patch -p1 &&
  make                         &&
  # Hack to avoid mayhem if libsafe is removed by dispel
  perl -i -pe 's:\S*/libsafe.\S*::' $INSTALL_ROOT/etc/ld.so.preload &&
