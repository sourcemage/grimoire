[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST} --build=${BUILD}"

GHC_DIR=ghc

make_single  &&

if [[ $SOURCE2 != "" ]] ; then
  cd ghc-bin &&
  ./configure &&
  if [ "$(uname -m)" == x86_64 ]; then
    echo 'SplitObjs=NO' > ../$SPELL-$VERSION/mk/build.mk
  fi   &&
  make in-place &&
  GHC_DIR=$PWD/bin/$ARCH-unknown-linux/ghc &&
  cd ..
fi &&

cd $SPELL-$VERSION &&

OPTS="$OPTS --with-ghc=$GHC_DIR --with-hc=$GHC_DIR"  &&
default_build
