if [ "${SMGL_COMPAT_ARCHS[1]}" = "ia32" ]; then
	 OPTS="$OPTS  --enable-simd"
else 
         OPTS="$OPTS  --disable-simd" 
fi &&

#if [ `uname -m` != "ppc" ]
#then
#  OPTS="$OPTS  --enable-simd" 
#else
#  OPTS="$OPTS  --disable-simd"
#fi  &&

if  [  "$IPV6"  ==  "y"  ]
then
  OPTS="$OPTS  --enable-ipv6"
else
  OPTS="$OPTS  --disable-ipv6"
fi  &&

# Fix for gcc 3.4:
sedit  "s:};:}:"  libxmms/xmmsctrl.h  &&

default_build
