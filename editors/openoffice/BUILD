#              --with-vendor=\"Source Mage GNU/Linux\" \
#              --with-build-version="\"$(head -n1 ${SPELL_DIRECTORY}/HISTORY |awk '{print $2, $3}' )\"" \
#              --with-system-headers \
#              --with-system-libs \
#              --with-system-stdlibs \
 
OPTS="${OPTS} ${OOO_OPTS}" &&
if [[ "${OOO_BINFILTER}" = 'n' ]]; then
  OPTS="${OPTS} --disable-binfilter"
fi &&
export PKGFORMAT="installed" &&
export SRC_ROOT="${SOURCE_DIRECTORY}" &&

cd ${SOURCE_DIRECTORY} &&
./configure   --prefix=${INSTALL_ROOT}/usr \
              --sysconfdir=${INSTALL_ROOT}/etc \
              --localstatedir=${INSTALL_ROOT}/var \
              --mandir=${INSTALL_ROOT}/usr/share/man \
              --infodir=${INSTALL_ROOT}/usr/share/info \
              --with-dict \
              --with-x \
              --disable-epm \
              --disable-odk \
              --disable-mathmldtd \
              --disable-qadevooo \
              --with-vendor="Source\ Mage\ GNU/Linux" \
              $OPTS &&

./bootstrap &&
source Linux*Env.Set.sh &&
dmake
