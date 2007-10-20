# install gcc libraries to /lib instead of /lib64
sedit "s/lib64/lib/" gcc/config/i386/linux64.h            &&
if [[ "$GCC_NOLIB64" == 'y' ]]; then
  # tell gcc to target binaries to expect the linker in /lib instead of /lib64
  sedit "s/lib64/lib/" gcc/config/i386/t-linux64           
fi                                                        &&

if  [[ "$ARCHITECTURE"  ==  "pentium4"  ||
       "$ARCHITECTURE"  ==  "pentium-m"  ]];  then
  CFLAGS=${CFLAGS//-ffast-math/}
  CXXFLAGS=${CXXFLAGS//-ffast-math/}
fi  &&

# store CFLAGS and LDFLAGS persistently so they can be read by the other
# split spells later, see bug #10087
GCC_CFLAGS="$CFLAGS"                   &&
GCC_LDFLAGS="$LDFLAGS"                 &&
persistent_add GCC_CFLAGS GCC_LDFLAGS  &&

cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                                \
             --host=$HOST                                  \
             --prefix=${INSTALL_ROOT}/usr                  \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
             --mandir=${INSTALL_ROOT}/usr/share/man        \
             --enable-threads=posix                        \
             --program-suffix=-${VERSION%.*}               \
             --with-system-zlib                            \
             $GCC_MULTILIB $OPTS                          &&

make CFLAGS="$CFLAGS" BOOT_CFLAGS="$CFLAGS" LDFLAGS="$LDFLAGS" \
     profiledbootstrap &&
make DESTDIR=$SOURCE_DIRECTORY.install install-no-fixedincludes &&

# set up specs file handling
local SPECSDIR=$SOURCE_DIRECTORY.install/usr/lib/gcc/$HOST/$VERSION         &&
mkdir -p $SPECSDIR/specs-local                                    &&
cp  gcc/specs  $SPECSDIR/specs-local/specs-gcc                    &&
if [[ $HOST == x86_64-* && $GCC_NOLIB64 == n ]]
then
  # make sure the linker gets compiled in as a /lib64 one
  sed -i 's#/lib/ld-linux-x86-64.so.2#/lib64/ld-linux-x86-64.so.2#' $SPECSDIR/specs-local/specs-gcc
fi &&
# make sure installwatch tracks it, the cat alone doesn't do that
touch  $SPECSDIR/specs                                            &&
cat  $SPECSDIR/specs-local/* > $SPECSDIR/specs

