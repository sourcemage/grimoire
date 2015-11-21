if is_depends_enabled  $(get_spell_provider $SPELL LIBAVCODEC) faac;  then
  OPTS="--enable-fdk-aac ${OPTS}"
else
  OPTS="--disable-fdk-aac ${OPTS}"
fi  &&

./configure --prefix="${INSTALL_ROOT}/usr"  \
            --launch                        \
            --launch-jobs=${MAKE_NJOBS}     \
            ${OPTS}                         &&
cd build &&
make
