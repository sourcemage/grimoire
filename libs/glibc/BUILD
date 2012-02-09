# install x86_64 linker to lib instead of lib64
sedit "s/lib64/lib/"  sysdeps/unix/sysv/linux/x86_64/ldconfig.h &&
sedit "s/264/2/" sysdeps/unix/sysv/linux/x86_64/ldd-rewrite.sed &&

# this causes configure to be run again where it fails for some people on PIII and for me on Alpha
# the error is about no working grep found...
if [[ ${SMGL_COMPAT_ARCHS[1]} == x86_64 ]]; then
# install x86_64 libraries to lib instead of lib64
sedit "s/| x86_64//"       sysdeps/unix/sysv/linux/configure    &&
sedit "s/| x86_64//"       sysdeps/unix/sysv/linux/configure.in
fi &&

local ADDONS
  ADDONS="nptl"                &&
  #
  # Enable IDN?
  #
  if  [  "$GLIBC_USEIDN" = "y"  ];  then
    ADDONS="$ADDONS libidn"
  fi  &&

  OPTS="$OPTS  --with-tls             \
               --enable-kernel=2.6"

OPTS="$OPTS --enable-add-ons=${ADDONS/ /,}"  &&

# minimise optimisation level
  CFLAGS="${CFLAGS//-O?/}"  &&
  CFLAGS="-O2 ${CFLAGS//-Os/}"

export  CFLAGS="${CFLAGS/-ffast-math/}"  &&
export  CC=gcc                           &&

#
# LD_LIBRARY_PATH includes $PWD bug
#
unset  LD_LIBRARY_PATH  &&

#
# Setup sanitised glibc-kernel-headers for the glibc compile
# ...as well as other arch-dependend specialties
#
  cd ${GLIBC_HEADERS_DIR} &&
  GL_ARCH=${SMGL_COMPAT_ARCHS[1]}  &&
  if [[ ${SMGL_COMPAT_ARCHS[0]} == 64 ]];then
  else
    if [[ ${SMGL_COMPAT_ARCHS[1]} == ia32 ]]; then
     GL_ARCH=i386
    fi
  fi &&
  make ARCH=$GL_ARCH INSTALL_HDR_PATH=usr headers_install


# CPPFLAGS setting is needed so the check for cpp works on boxes that don't
# have any kernel headers in /usr/include yet
export CPPFLAGS="$CPPFLAGS -I$GLIBC_HEADERS_DIR/usr/include"  &&
#
# End sanitised glibc-kernel-headers setup
#

# this is weird but nscd needs this header from libcap but not the rest of
# the standard includes so doing this will make nscd pick it up
mkdir -p $SOURCE_DIRECTORY/nscd/sys &&
ln -s /usr/include/sys/capability.h $SOURCE_DIRECTORY/nscd/sys/capability.h &&

#
# Change to where we're going to actually build
#
cd  $SOURCE_DIRECTORY.bld  &&

#
# Configure glibc to use the sanitised headers
# http://bugs.sourcemage.org/show_bug.cgi?id=7560
#
$SOURCE_DIRECTORY/configure  --host=$HOST                       \
                            --build=$BUILD                      \
                           --prefix=/usr                        \
                          --infodir=/usr/share/info             \
                           --mandir=/usr/share/man              \
                       --sysconfdir=/etc                        \
                             --with-elf                         \
                           --enable-shared                      \
                          --disable-profile                     \
                     --with-headers=$GLIBC_HEADERS_DIR/usr/include  \
                          --disable-multi-arch                  \
                                    $OPTS                       &&
make
