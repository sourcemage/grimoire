mkdir  -p  ${INSTALL_ROOT}/var/chroot/ntp/

create_account  ntp  &&

for i in $(grep -rl CONFIG_PHONE .);  do
  sedit  "s/CONFIG_PHONE/NTP_CONFIG_PHONE/g"  $i
done  &&

./configure                                  \
  --build=$BUILD                             \
  --prefix=${INSTALL_ROOT}/usr               \
  --sysconfdir=${INSTALL_ROOT}/etc           \
  --localstatedir=${INSTALL_ROOT}/var/cache  \
  --libexecdir=${INSTALL_ROOT}/usr/bin       \
  --enable-linuxcaps                         \
  $OPTS                                      &&
make
