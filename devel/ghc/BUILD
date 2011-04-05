[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"

GHC_DIR=/usr/bin

make_single &&

if [[ $SOURCE2 != "" ]] ; then
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
make
