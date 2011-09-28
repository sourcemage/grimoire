# Clean out the old alsa drivers. FIXME: Bad location for 2.6!
rm -f ${INSTALL_ROOT}/lib/modules/$(get_kernel_version)/misc/snd* &&

if [[ $(get_sorcery_kernel_config CONFIG_SOUND) == m ||
`grep -c CONFIG_SOUND=m ${CONFIG_CACHE}/kernel.config` == 1 ]]
then
  modprobe -q soundcore
fi &&

sedit "s:/usr/bin/awk:${TRACK_ROOT}/bin/awk:" utils/convert_isapnp_ids &&
sedit "s: install-scripts : :" Makefile &&

OPTS="--with-isapnp=yes --with-sequencer=yes --with-oss=yes --with-debug=none \
      --with-moddir=${INSTALL_ROOT}/lib/modules/$(get_kernel_version)/misc    \
      --with-kernel=${INSTALL_ROOT}/lib/modules/$(get_kernel_version)/source  \
      --with-cards=${CARDS} ${OPTS}"                                          &&

if [[ $ALSA_DRIVER_BRANCH == scm ]]; then
export ALSAKERNELDIR="$SOURCE2_DIRECTORY" &&
  OPTS="--prefix=${INSTALL_ROOT}/usr \
    --sysconfdir=${INSTALL_ROOT}/etc \
 --localstatedir=${INSTALL_ROOT}/var \
        --mandir=${INSTALL_ROOT}/usr/share/man \
       --infodir=${INSTALL_ROOT}/usr/share/info \
                 $OPTS" &&
  ./gitcompile $OPTS
else
  sedit "s:root.root:root.audio:" snddevices &&
  default_build
fi
