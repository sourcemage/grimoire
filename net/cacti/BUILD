# apply the official patches
for patch in `gaze sources $SPELL | grep "\.patch$"`; do
  patch -p1 < "$SOURCE_CACHE/$patch"
done
