src/configure &&

make -C src &&

if list_find "$LDFLAGS" "-s"; then
  strip -v "libexec/pyenv-realpath.dylib"
fi
