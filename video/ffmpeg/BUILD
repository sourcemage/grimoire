disable_pic  &&

if list_find "$FFMPEG_PROGRAMS" "none"; then
  OPTS="--disable-programs $OPTS"
elif list_find "$FFMPEG_PROGRAMS" "all"; then
  :
else
  for program in $FFMPEG_PROGRAM_LIST; do
    if ! list_find "$FFMPEG_PROGRAMS" "$program"; then
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

# license handling (nonfree/GPLv3)
if is_depends_enabled $SPELL openssl || \
   is_depends_enabled $SPELL faac; then
    OPTS="--enable-nonfree $OPTS"
fi &&

if is_depends_enabled $SPELL opencore-amr; then
    OPTS="--enable-version3 $OPTS"
fi &&

# fixing issue #381
if is_depends_enabled $SPELL openjpeg; then
    CFLAGS="$CFLAGS -I${INSTALL_ROOT}/usr/include/openjpeg-1.5"
fi &&

LDFLAGS=${LDFLAGS//-Wl,--as-needed/}  &&

check_tmp_noexec /tmp &&
./configure  --prefix=${INSTALL_ROOT}/usr            \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --enable-shared                         \
             --disable-static                        \
             --enable-pthreads                       \
             --enable-postproc                       \
             --enable-gpl                            \
             $OPTS                         &&
check_tmp_noexec /tmp &&
make V=1 &&
make V=1 tools/qt-faststart
