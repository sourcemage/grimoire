sh ./Build.sh -r &&
gzip -n9 mksh.1 &&

if [[ $MKSH_TEST == y ]]; then
  ./test.sh -v > "$INSTALL_ROOT/tmp/mksh.test.log" 2>&1
fi
