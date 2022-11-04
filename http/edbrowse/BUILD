make -C src -j "$MAKE_NJOBS" \
     QUICKJS_DIR="$INSTALL_ROOT"/usr/include/quickjs \
     QUICKJS_LDFLAGS="-L$INSTALL_ROOT/usr/lib/quickjs -lquickjs -ldl -latomic" \
     CC="${CC:-cc}"
