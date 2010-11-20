OPTS="${OPTS} ${OOO_OPTS}" &&
if [[ "${OOO_BINFILTER}" = 'n' ]]; then
  OPTS="${OPTS} --disable-binfilter"
fi &&

if [[ "${MAKE_NJOBS}" = "" ]]; then
  MAKE_NJOBS=1
fi

cd ${SOURCE_DIRECTORY} &&

./configure   --prefix=${INSTALL_ROOT}/opt \
              --sysconfdir=${INSTALL_ROOT}/etc \
              --localstatedir=${INSTALL_ROOT}/var \
              --mandir=${INSTALL_ROOT}/usr/share/man \
              --infodir=${INSTALL_ROOT}/usr/share/info \
              --with-vendor="Source Mage GNU/Linux" \
              --disable-epm \
              --with-use-shell=bash \
              --with-system-stdlibs \
              --without-myspell-dicts \
              --with-system-dicts \
              --with-lang="$OOO_LANG" \
              $OPTS 

sedit 's/testautomation//' instsetoo_native/prj/build.lst &&
source Linux*Env.Set.sh &&
./bootstrap &&
nodep=TRUE NO_HIDS=TRUE dmake -P${MAKE_NJOBS}
