export TOPDIR="$SOURCE_DIRECTORY" &&
default_build_configure &&
sed -i '/^COMMON_CFLAGS/ s,$, -fPIC,' config/Linux.mak &&
default_build_make
