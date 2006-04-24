# Clean out the old alsa drivers.
rm  -f  /lib/modules/`installed_version linux-new`/misc/snd*  &&

if [ -e /proc/config.gz ] ; then
    if [ `zgrep -c CONFIG_SOUND=m /proc/config.gz` = 1 ] ; then
	modprobe -q soundcore
    fi
elif [ `grep -c CONFIG_SOUND=m /etc/sorcery/local/kernel.config` = 1 ] ; then
    modprobe -q soundcore
fi



sedit  "s:/usr/bin/awk:/bin/awk:"  utils/convert_isapnp_ids  &&
sedit  "s: install-scripts : :"    Makefile                  &&
sedit  "s:root.root:root.audio:"   snddevices                &&

./configure  --prefix=/usr         \
             --with-isapnp=yes     \
             --with-sequencer=yes  \
             --with-oss=yes        \
             --with-debug=none     \
             --with-cards=$CARDS   \
             $OPTS                 &&
make_single                        &&
make
