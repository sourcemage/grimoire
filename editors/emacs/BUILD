# don't make it track all info files in /usr/share/info
#  sedit  's:${COPYDESTS} ${infodir}:${COPYDESTS}:'  Makefile.in  &&

case "$HOST" in
  (*-musl)
    # Workaround bug in libexecinfo spell that causes temacs to crash during
    # bootstrap. Last tested with libexecinfo 1.1.
    OPTS+=' ac_cv_header_execinfo_h=no'
    ;;
esac

# Fixes Bug #2938
export  LDFLAGS="${LDFLAGS/-z combreloc/}"  &&

#
# Fails to link if using -Wl,-O1
#
export LDFLAGS="${LDFLAGS//-Wl,-O1/}"  &&

# XXX Causes a segfault during the bootstrapping
CFLAGS="${CFLAGS//-ftree-loop-if-convert-stores}" &&
# XXX Emacs 27.1 fails to build if restricted to finite math
CFLAGS="${CFLAGS//-ffast-math}" &&

OPTS="${OPTS} --with-x-toolkit=${EMACS_XTOOLKIT} ${EMACS_OPTS}" &&

if [[ "$EMACS_XTOOLKIT" == "no" ]]; then
  OPTS+=" --without-x"
fi &&

if [[ "$EMACS_BRANCH" == "scm" ]]; then
  # Crashes with -O3
  export  CFLAGS="${CFLAGS//-O3/-O2}"      &&

  default_build_configure &&
  make bootstrap
else
  default_build
fi
