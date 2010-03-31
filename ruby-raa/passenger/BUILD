if list_find "$OPTS" "APACHE=1"; then
  rake apache2
fi &&

if is_depends_enabled $SPELL nginx; then
  rake nginx
fi &&

rm -rf old.binaries old.libraries &&

find "$SOURCE_DIRECTORY" -name '*.[a|o]' -delete
