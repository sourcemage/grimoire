case "$HOST" in
i[3456]86-*)  arch=i386   ;;
x86_64-x32-*) arch=x32    ;;
x86_64-*)     arch=x86_64 ;;
*)
    echo "Unknown architecture for $HOST."
    return 1
esac &&
make $OPTS \
     LINKER_PATH="/lib/ld-musl-$arch.so.1"
