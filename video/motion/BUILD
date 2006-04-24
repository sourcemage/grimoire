if (spell_ok ffmpeg || spell_ok ffmpeg-cvs); then
  zcat $SCRIPT_DIRECTORY/motion-3.1.18_snap7-ffmpeg.patch.gz | patch -p1
fi						     &&

sh ./configure  --prefix=${INSTALL_ROOT}/usr         \
                --sysconfdir=${INSTALL_ROOT}/etc     \
                --localstatedir=${INSTALL_ROOT}/var  \
                --without-mysql                      \
                --without-pgsql                      \
                $OPTS                                &&
make
