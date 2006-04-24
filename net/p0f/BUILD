if [ ! -e /usr/include/net/bpf.h ]; then
    sedit "s/<net\/bpf.h>/\"bpf.h\"/g" p0f.c
    cp $SCRIPT_DIRECTORY/bpf.h $BUILD_DIRECTORY/$SPELL
fi

./Build all &&
./Build install
