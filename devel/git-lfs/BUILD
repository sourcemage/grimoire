check_tmp_noexec /tmp &&
./script/bootstrap &&
check_tmp_noexec /tmp &&

if list_find "$LDFLAGS" "-s"; then
  strip -v "bin/git-lfs"
fi
