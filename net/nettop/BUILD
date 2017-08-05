CFLAGS="-Wall -std=c++0x -pthread -D_GLIBCXX_USE_NANOSLEEP ${CFLAGS}" &&

make FLAGS="${CFLAGS}" &&

if list_find "${LDFLAGS}" "-s"; then
  strip -v "nettop"
fi
