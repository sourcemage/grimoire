cd $SOURCE_DIRECTORY          &&
autoconf								&&
OPTS="${!tempopts} $OPTS"     &&
OPTS="$OPTS --build=${BUILD}" &&
./configure --prefix=${INSTALL_ROOT}/usr   \
            --disable-clntest      \
                     $OPTS    &&
default_build_make
