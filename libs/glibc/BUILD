make_single  &&

if [ "$GLIBC_NOLIB64" = "y" ]; then
  # install x86_64 linker to lib instead of lib64
  sedit "s/lib64/lib/"  sysdeps/unix/sysv/linux/x86_64/ldconfig.h &&
  sedit "s/264/2/" sysdeps/unix/sysv/linux/x86_64/ldd-rewrite.sed
fi                                                              &&

# install x86_64 libraries to lib instead of lib64
sedit "s/| x86_64//"       sysdeps/unix/sysv/linux/configure    &&
sedit "s/| x86_64//"       sysdeps/unix/sysv/linux/configure.in &&

#
# bug#5570 ccache sometimes has trouble correctly recognising minor differences 
# in configurations and doesn't force recompile when it should. This stops it from
# using the old cache entries.
#
export  CCACHE_RECACHE=true  &&
#
# End ccache fix
#

if  [  "$GLIBC_NPTL"  =  "y"  ];  then
  OPTS="$OPTS  --enable-add-ons=nptl  \
               --with-tls             \
               --enable-kernel=2.6"
else
  OPTS="$OPTS  --enable-add-ons=linuxthreads  \
               --without-__thread \
               --enable-kernel=2.4"
fi  &&

#
# Fixes Bug #8595
#
CFLAGS="-Os $CFLAGS"  &&

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
persistent_add  GLIBC_ARCH  &&
if [[ ${SMGL_COMPAT_ARCHS[1]} == x86_64 ]]; then
  GLIBC_ARCH=x86_64    
elif [[ ${SMGL_COMPAT_ARCHS[1]} == ppc ]]; then
  GLIBC_ARCH=ppc
elif [[ ${SMGL_COMPAT_ARCHS[1]} == ia32 ]]; then
  GLIBC_ARCH=i386
elif [[ ${SMGL_COMPAT_ARCHS[0]} == 64 && ${SMGL_COMPAT_ARCHS[1]} == sparc ]]; then
  #
  # If we're not compiling for 64-bit SPARC then we need to use the sparc
  # headers, not sparc64
  #
  if  echo  "$CFLAGS"  |  grep  -q  --  "-m64";  then
    GLIBC_ARCH=sparc64  &&
    export  CC=gcc64
  else
    GLIBC_ARCH=sparc
  fi  &&

  #
  # Fixes from Gentoo's 2.3.3.20040420-r2 ebuild
  #
  sedit  "s:CPPFLAGS += -DHAVE_INITFINI:CPPFLAGS += -DHAVE_INITFINI -fno-pie -fno-PIE:"  csu/Makefile
  export    CFLAGS="${CFLAGS/-fcall-used-g7/}"
  export    CFLAGS="$CFLAGS  -fcall-used-g6"
  export    CFLAGS="${CFLAGS/-mcpu=v9/}"
  export    CFLAGS="${CFLAGS/-mtune=ultrasparc/}"
  export    CFLAGS="${CFLAGS/-mvis/}"

  # Setup the HOST properly to insure "sparcv9"
  # This passes -mcpu=ultrasparc -Wa,-Av9a to the compiler
  [  "$HOST"  =  "sparc-unknown-linux-gnu"  ]   &&  
  export HOST="sparcv9-unknown-linux-gnu"       &&
  [  "$BUILD"  =  "sparc-unknown-linux-gnu"  ]  &&  
  export BUILD="sparcv9-unknown-linux-gnu"
elif [[ ${SMGL_COMPAT_ARCHS[0]} == 32 && ${SMGL_COMPAT_ARCHS[1]} == sparc ]]; then
  GLIBC_ARCH=sparc  &&
  #
  # Fixes from Gentoo's 2.3.3.20040420-r2 ebuild
  #
  sedit  "s:CPPFLAGS += -DHAVE_INITFINI:CPPFLAGS += -DHAVE_INITFINI -fno-pie -fno-PIE:"  csu/Makefile
  export    CFLAGS="${CFLAGS/-fcall-used-g7/}"
  export    CFLAGS="$CFLAGS  -fcall-used-g6"
elif [[ ${SMGL_COMPAT_ARCHS[1]} == alpha ]]; then
  # This is a first attempt to get alpha going, being paranoid about any CFLAGS,
  # not without reason: -Os/-O breaks compile in strange ways:
  #  either an elf/ld.so that segfaults (build failing at sunrpc) or
  #  internal compiler error(s) in intl/
  # glibc knows itself what flags to choose
  export CFLAGS="" &&
  GLIBC_ARCH=alpha
else
  message "Glibc spell doesn't know your architecture!" &&
  false
fi &&

# set the asm headers to point to the correct architecture
cd  $GLIBC_HEADERS_DIR/include  &&
ln  -sf  asm-$GLIBC_ARCH  asm   &&

# CPPFLAGS setting is needed so the check for cpp works on boxes that don't
# have any kernel headers in /usr/include yet
export CPPFLAGS="$CPPFLAGS -I$GLIBC_HEADERS_DIR/include"  &&
#
# End sanitised glibc-kernel-headers setup
#

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
                     --with-headers=$GLIBC_HEADERS_DIR/include  \
                                    $OPTS                       &&
make
