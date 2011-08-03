if [ "$ARCH_SPECIFIC" == "y" ]; then
    sedit "s#CFLAGS = -s -static -Wall -O3#CFLAGS = -s -static -Wall -O3 $CFLAGS#" Makefile 	&&
    sedit "s/#LINKFLAGS = -s/LINKFLAGS = $LDFLAGS/" Makefile
fi &&

make_single &&
make        &&
make_normal
