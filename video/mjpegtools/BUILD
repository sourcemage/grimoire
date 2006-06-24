# fix bug #6403
sedit  's/ARCHFLAGS="-mcpu=i786 -march=$arch"/ARCHFLAGS=""/'  configure  &&
sedit  's/ARCHFLAGS="-mcpu=i686 -march=$arch"/ARCHFLAGS=""/'  configure  &&
sedit  's/ARCHFLAGS="-mcpu=i586 -march=$arch"/ARCHFLAGS=""/'  configure  &&

# fails to compile with -DPIC and -fPIC except on AMD64
# ...and Alpha; where mjpegtools configure sets PIC anyway - disabling
# here doesn't hurt but doesn't make sense, either.
if [[ ${SMGL_COMPAT_ARCHS[1]} != alpha ]]; then
	disable_pic
fi &&

OPTS="--without-libquicktime $OPTS"  &&
make_single                                                   &&
default_build                                                 &&
make_normal
