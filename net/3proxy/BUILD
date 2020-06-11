local PLUGINS &&
local LIBS="-ldl" &&

if list_find "${THREE_PROXY_PLUGINS}" "default"; then
  PLUGINS="StringsPlugin TrafficPlugin PCREPlugin TransparentPlugin"
elif list_find "${THREE_PROXY_PLUGINS}" "none"; then
  PLUGINS=""
elif list_find "${THREE_PROXY_PLUGINS}" "all"; then
  PLUGINS="SSLPlugin StringsPlugin TrafficPlugin PCREPlugin TransparentPlugin PamAuth"
else
  PLUGINS="${THREE_PROXY_PLUGINS}"
fi &&

if list_find "${PLUGINS}" "PCREPlugin"; then
  LIBS="-lpcre ${LIBS}"
fi &&

if list_find "${PLUGINS}" "SSLPlugin"; then
  LIBS="-lcrypto -lssl ${LIBS}"
fi &&

if list_find "${PLUGINS}" "PamAuth"; then
  LIBS="-lpam ${LIBS}"
fi &&

if list_find "${PLUGINS}" "LdapPlugin"; then
  LIBS="-lldap ${LIBS}"
fi &&

make_single &&
make -f Makefile.Linux PLUGINS="${PLUGINS}" LIBS="${LIBS}" &&
make_normal
