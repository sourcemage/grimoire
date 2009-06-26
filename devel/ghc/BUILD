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

PATH="$GHC_DIR:$PATH" &&
default_build
