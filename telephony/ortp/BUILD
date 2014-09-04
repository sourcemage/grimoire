# fix compilation issue with gcc 4.6.x
OPTS="${OPTS} --disable-strict" &&

# build 64bit library on such system
if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" ]]; then
    OPTS="${OPTS} --enable-mode64bit=yes"
fi &&

default_build
