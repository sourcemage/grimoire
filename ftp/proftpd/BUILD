if [[ $PROFTPD_DEVEL == "n" ]]; then
  if [[ -z $PROFTPD_CAPS ]]; then
      CFLAGS=${CFLAGS/-fPIC}                                          &&
      CFLAGS=${CFLAGS/-DPIC}                                          &&
      CXXFLAGS=${CXXFLAGS/-fPIC}                                      &&
      CXXFLAGS=${CXXFLAGS/-DPIC}                
  fi
fi                                                                    &&

sedit  "s/	standalone/	inetd/"  sample-configurations/basic.conf     &&

OPTS="${PROFTPD_CAPS} ${PROFTPD_MODS} ${OPTS}"                        &&

./configure  --prefix=${INSTALL_ROOT}/usr                             \
             --sysconfdir=${INSTALL_ROOT}/etc                         \
             --localstatedir=${INSTALL_ROOT}/var/run                  \
             --mandir=$INSTALL_ROOT/usr/share/man                     \
             --enable-shadow                                          \
             ${OPTS}                                                  &&

sedit  's:RUN_DIR.*"/var/run/proftpd":RUN_DIR "/var/run":'  config.h  &&
sedit  's:rundir=/var/run/proftpd:rundir=/var/run:'  Make.rules       &&

make
