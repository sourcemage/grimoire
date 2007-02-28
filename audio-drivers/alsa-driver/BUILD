# Clean out the old alsa drivers. FIXME: Bad location for 2.6!
rm  -f  ${TRACK_ROOT}/lib/modules/`get_kernel_version`/misc/snd*  &&

if [ -e ${TRACK_ROOT}/proc/config.gz ] ; then
    if [ `zgrep -c CONFIG_SOUND=m ${TRACK_ROOT}/proc/config.gz` = 1 ] ; then
	modprobe -q soundcore
    fi
elif [ `grep -c CONFIG_SOUND=m ${TRACK_ROOT}/etc/sorcery/local/kernel.config` = 1 ] ; then
    modprobe -q soundcore
fi  &&

sedit  "s:/usr/bin/awk:${TRACK_ROOT}/bin/awk:"  utils/convert_isapnp_ids  &&
sedit  "s: install-scripts : :"                 Makefile                  &&
sedit  "s:root.root:root.audio:"                snddevices                &&

OPTS="--with-isapnp=yes --with-sequencer=yes --with-oss=yes --with-debug=none  \
      --with-moddir=${INSTALL_ROOT}/lib/modules/$(get_kernel_version)/misc     \
       --with-cards=${CARDS} ${OPTS}"                                          &&

default_build
