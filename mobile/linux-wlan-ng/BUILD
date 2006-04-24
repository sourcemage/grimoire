patch -p0 < $SPELL_DIRECTORY/mk.diff etc/Makefile			&&
sedit "s:/local::" man/Makefile					&&
sedit "s:/usr/src/linux:/lib/modules/$(get_kernel_version)/build:" config.in	&&
if [[ -f ${CONFIG_CACHE}/${SPELL}.config ]] ; then
	cp -v ${CONFIG_CACHE}/${SPELL}.config ./config.out
fi &&
if [[ $RECONFIGURE ]] && [[ "$WLAN_NG_RECONF" == "y" ]] ; then
	message "${MESSAGE_COLOR}The installed kernel is: $(get_kernel_version)${DEFAULT_COLOR}" &&
	./Configure &&
	cp -v ./config.out ${CONFIG_CACHE}/${SPELL}.config
fi &&
make all 		
