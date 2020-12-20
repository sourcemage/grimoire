disable_as_needed &&
disable_relro     &&
disable_z_now     &&

default_build_make &&

if list_find "$LDFLAGS" "-s"; then
  strip -v "bin/git-lfs"
fi
