# don't make it track all info files in /usr/share/info
#  sedit  's:${COPYDESTS} ${infodir}:${COPYDESTS}:'  Makefile.in  &&

# Fixes Bug #2938
export  LDFLAGS="${LDFLAGS/-z combreloc/}"  &&

#
# Fails to link if using -Wl,-O1
#
export LDFLAGS="${LDFLAGS//-Wl,-O1/}"  &&

# XXX Causes a segfault during the bootstrapping
CFLAGS="${CFLAGS/-ftree-loop-if-convert-stores}" &&

OPTS="${OPTS} --with-x-toolkit=${EMACS_XTOOLKIT} ${EMACS_OPTS}" &&
if [[ "$EMACS_BRANCH" == "scm" ]]; then
  # Crashes with -O3
  export  CFLAGS="${CFLAGS//-O3/-O2}"      &&

  default_build_configure &&
  make bootstrap
else
  default_build
fi
