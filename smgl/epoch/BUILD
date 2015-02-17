rm -r -f objects sbin &&
mkdir -p objects sbin &&

cd objects &&
if [ -z $CC ]; then
  CC=gcc
fi &&
$CC $CFLAGS -c ../src/actions.c &&
$CC $CFLAGS -c ../src/config.c &&
$CC $CFLAGS -c ../src/console.c &&
$CC $CFLAGS -c ../src/main.c &&
$CC $CFLAGS -c ../src/membus.c &&
$CC $CFLAGS -c ../src/modes.c &&
$CC $CFLAGS -c ../src/parse.c &&
$CC $CFLAGS -c ../src/utilfuncs.c &&

$CC $CFLAGS -o ../sbin/epoch \
 actions.o config.o console.o main.o membus.o modes.o parse.o utilfuncs.o \
 $LDFLAGS
