# for some reason sedit is not accepting both files...
for _MAKEFILE in icap/Makefile mstore/Makefile; do
  sedit "s|CFLAGS=|CFLAGS=$CFLAGS |g" $_MAKEFILE
done &&
cd ./icap/   && make && cd .. &&
cd ./mstore/ && make && cd .. &&

OPTS="$OPTS --with-icap --with-mstore" &&
persistent_add OTHER_CFLAGS="$CFLAGS" &&
default_build
