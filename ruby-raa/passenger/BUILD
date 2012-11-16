if list_find "$OPTS" "APACHE=1"; then
  rake apache2
fi &&

if is_depends_enabled $SPELL nginx; then
  rake nginx
fi &&

if [[ $PASSENGER_BRANCH == 3 ]]; then
  rm -rf ext/libev/.libs
fi &&

# post-build cleanup
find "$SOURCE_DIRECTORY" -name '*.[a|o]' -delete
