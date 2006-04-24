# for some reason sedit is not accepting both files...
for _MAKEFILE in icap/Makefile mstore/Makefile; do
  sedit "s|CFLAGS=|CFLAGS=$CFLAGS |g" $_MAKEFILE
done &&
invoke_gcc &&
cd ./icap/   && make && cd .. &&
cd ./mstore/ && make && cd .. &&

OPTS="$OPTS --with-icap --with-mstore" &&
export OTHER_CFLAGS="$CFLAGS" &&
default_build
