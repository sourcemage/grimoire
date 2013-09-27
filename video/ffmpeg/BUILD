disable_pic  &&

if list_find "$FFMPEG_PROGRAMS" "none"; then
  OPTS="--disable-programs $OPTS"
elif list_find "$FFMPEG_PROGRAMS" "all"; then
  :
else
  for program in $FFMPEG_PROGRAM_LIST; do
    if ! list_find "$program" "$FFMPEG_PROGRAMS"; then
      OPTS="--disable-$program $OPTS"
    fi
  done &&

  persistent_remove FFMPEG_PROGRAM_LIST &&
  persistent_save &&
  persistent_load
fi &&

OPTS="$FFMPEG_OPTS $OPTS" &&

if echo "$CFLAGS" | grep -q "\-Os"; then
  OPTS="--enable-small $OPTS"
fi &&

# fixing issue #381
if is_depends_enabled $SPELL openjpeg; then
    CFLAGS="$CFLAGS -I${INSTALL_ROOT}/usr/include/openjpeg-1.5"
fi &&

LDFLAGS=${LDFLAGS//-Wl,--as-needed/}  &&

./configure  --prefix=${INSTALL_ROOT}/usr            \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --enable-shared                         \
             --disable-static                        \
             --enable-pthreads                       \
             --enable-postproc                       \
             --enable-gpl                            \
             $OPTS                         &&

make V=1 &&
make V=1 tools/qt-faststart
