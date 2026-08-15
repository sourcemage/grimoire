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

cd $SOURCE_DIRECTORY/ghc-bin &&
./configure --prefix=$SOURCE_DIRECTORY/ghc-bin-installed &&
make install &&

BOOT_GHC=$SOURCE_DIRECTORY/ghc-bin-installed/bin/ghc &&

# bootstrap.py always builds into ./_build, so give it a directory of its own;
# it finds the in-tree packages relative to the script, not to $PWD.  With the
# sources tarball it neither needs the network nor cabal-install.
mkdir -p $SOURCE_DIRECTORY/hadrian-boot &&
cd $SOURCE_DIRECTORY/hadrian-boot &&
python3 $SOURCE_DIRECTORY/$SPELL-$VERSION/hadrian/bootstrap/bootstrap.py \
        --no-archive                                                     \
        -w $BOOT_GHC                                                     \
        -s $SOURCE_CACHE/$SOURCE3                                        &&

cd $SOURCE_DIRECTORY/$SPELL-$VERSION &&

# Only --prefix and --with-ghc matter here; Hadrian installs through the
# binary distribution's own configure, which is run again in INSTALL.
./configure --prefix=${INSTALL_ROOT}/usr  \
            --with-ghc=$BOOT_GHC          \
                       $OPTS              &&

$SOURCE_DIRECTORY/hadrian-boot/_build/bin/hadrian \
    -j$MAKE_NJOBS                                 \
    --flavour=perf                                \
    --docs=none                                   \
    binary-dist-dir
