GHC_DIR=/usr/bin

echo "BuildFlavour = perf"      >> "${SPELL}-${VERSION}/mk/build.mk" &&
echo "V = 0"                    >> "${SPELL}-${VERSION}/mk/build.mk" &&
echo "XSLTPROC_OPTS += --nonet" >> "${SPELL}-${VERSION}/mk/build.mk" &&
echo "BUILD_SPHINX_HTML = NO"   >> "${SPELL}-${VERSION}/mk/build.mk" &&
echo "BUILD_SPHINX_PDF = NO"    >> "${SPELL}-${VERSION}/mk/build.mk" &&

if [[ -x ${INSTALL_ROOT}/usr/bin/ghc-pkg-7.2.1 ]]; then
  ghc-pkg-7.2.1 trust base
fi &&

# ld.gold and ld.lld are chosen first, but don't support -z{,no}separate-code
if type ld.gold || type ld.lld; then
  case "$LD" in
  ld|ld.bfd)
    ;;
  *)
    LDFLAGS="${LDFLAGS//-Wl,-znoseparate-code}"
    LDFLAGS="${LDFLAGS//-Wl,-zseparate-code}"
    ;;
  esac
fi > /dev/null

if ! spell_ok "$SPELL"; then
  cd ghc-bin &&
  ./configure --prefix=${SOURCE_DIRECTORY}/ghc-bin-installed &&
  if [ "$(uname -m)" == x86_64 ]; then
    echo 'SplitObjs = NO' >> ../$SPELL-$VERSION/mk/build.mk
  fi &&
  make install &&
  GHC_DIR=${SOURCE_DIRECTORY}/ghc-bin-installed/bin &&
  cd ..
fi &&

cd $SPELL-$VERSION &&

./configure   --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
            --with-ghc=$GHC_DIR/ghc                    \
                       $OPTS                 &&
default_build_make
