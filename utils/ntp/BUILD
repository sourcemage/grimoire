create_account ntp &&

local GLIBCVER=$(installed_version glibc) &&
GLIBCVER=${GLIBCVER:0:3} &&

if [[ ! -z $GLIBCVER ]] && [[ ${GLIBCVER/.} > 24 ]]; then
    if list_find "$NTP_IPV6" "--enable-ipv6"; then
        OPTS="$OPTS --enable-getifaddrs=glibc"
    fi
fi &&

OPTS="$OPTS $NTP_IPV6" &&
default_build
