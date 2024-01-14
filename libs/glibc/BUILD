# clear cflags
unset CFLAGS

disable_fortify_source &&
disable_gc_sections    &&

if [[ $GLIBC_DEBUG == "y" ]]; then
  LDFLAGS="${LDFLAGS/-s/}"
fi &&


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
  make INSTALL_HDR_PATH=usr headers_install &&


# CPPFLAGS setting is needed so the check for cpp works on boxes that don't
# have any kernel headers in /usr/include yet
export CPPFLAGS="$CPPFLAGS -I$GLIBC_HEADERS_DIR/usr/include"  &&
#
# End sanitised glibc-kernel-headers setup
#

# Change to where we're going to actually build
#
cd  $SOURCE_DIRECTORY.bld  &&

# security-related options
OPTS+=" --enable-bind-now"                 &&
OPTS+=" --enable-stack-protector=strong"   &&
OPTS+=" --enable-stackguard-randomization" &&
OPTS+=" $GLIBC_CET"                        &&


#
# Configure glibc to use the sanitised headers
# http://bugs.sourcemage.org/show_bug.cgi?id=7560
#
$SOURCE_DIRECTORY/configure  --host=$HOST                       \
                            --build=$BUILD                      \
                           --prefix=/usr                        \
                           --libdir=/usr/lib                    \
                          --infodir=/usr/share/info             \
                           --mandir=/usr/share/man              \
                       --sysconfdir=/etc                        \
                             --with-elf                         \
                           --enable-shared                      \
                          --disable-profile                     \
			  --disable-werror                      \
                     --with-headers=$GLIBC_HEADERS_DIR/usr/include  \
                          --disable-multi-arch                  \
                    libc_cv_slibdir=/lib                        \
                                    $OPTS                       &&
LDFLAGS+=" -fuse-ld=bfd" &&
default_build_make &&

# fake install
mkdir -p "${SOURCE_DIRECTORY}.bld/INSTALL_ROOT" &&
make  install install_root="${SOURCE_DIRECTORY}.bld/INSTALL_ROOT"
