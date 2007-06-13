cd xmms2*  &&
if list_find "$XMMS2_OPTS" "--without-xmms2d=1" ; then
OPTS="$XMMS2_OPTS --with-mandir=${INSTALL_ROOT}/usr/share/man --without-plugins=diskwrite,html,id3v2,equalizer,null,m3u,cue,nulstripper,pls,icymetaint,ices,lastfm,lastfmeta,curl,vocoder,daap,file,asx,rss,xml,xspf,cdda,mms,samba,mad,vorbis,modplug,musepack,flac,sid,speex,faad,alsa,jack,mp4,oss,ao,wave,avformat,replaygain,gnomevfs,avcodec $OPTS"
else
OPTS="$XMMS2_OPTS --with-mandir=${INSTALL_ROOT}/usr/share/man --without-plugins=html,cdda,sid,speex $OPTS"
fi  &&
CCFLAGS=$CFLAGS waf_build
