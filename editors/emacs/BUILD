# don't make it track all info files in /usr/share/info
sedit  's:${COPYDESTS} ${infodir}:${COPYDESTS}:'  Makefile.in  &&
# Fixes Bug #2938
export  LDFLAGS="${LDFLAGS/-z combreloc/}"  &&
# add support for AMD64 (modified patch from Gentoo)
patch -p1 < $SCRIPT_DIRECTORY/emacs-21-amd64.diff &&
default_build
