sedit  "s/^dist:.*/dist: xen tools docs/"     Makefile    &&
sedit  "s:dst=\'/\':dst=\'$INSTALL_ROOT/\':"  install.sh  &&

# looks like xen doesn't like LDFLAGS optimizations
unset LDFLAGS &&
make  dist
