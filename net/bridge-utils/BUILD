OPTS="$OPTS --with-linux-headers=${INSTALL_ROOT}/lib/modules/$(get_kernel_version)/build" &&
cd ${SOURCE_DIRECTORY} &&
sed -i "23i#include <netinet/in.h>" libbridge/libbridge.h &&
aclocal &&
autoconf &&
default_build
