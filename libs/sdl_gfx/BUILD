unset  CFLAGS

# MMX fails on x86_64 as of version 2.0.16, but is enabled by default.
# That's why it needs to be disabled explicitly in the else statement below.
if [[ ${SMGL_COMPAT_ARCHS[0]} == "32"   ]] ||
   [[ ${SMGL_COMPAT_ARCHS[0]} == "ia32" ]]
then
    if [ "$MMX" == "n" ]; then
      OPTS="--disable-mmx  ${OPTS}"
    fi
else
    OPTS="--disable-mmx  ${OPTS}"
fi                                 &&

./configure  --build=$BUILD        \
             --prefix=/usr         \
             --sysconfdir=/etc     \
             --localstatedir=/var  \
             $OPTS                 &&
make
