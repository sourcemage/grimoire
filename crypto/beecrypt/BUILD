# Fixes compilation error:
# mpopt.s:62: Error: bad register name `%rdi'
# http://bugs.sourcemage.org/show_bug.cgi?id=15293#c2

if [[ "${SMGL_COMPAT_ARCHS[1]}" == "ia32" ]] ; then
  # Workaround for bad configure script
  export CFLAGS=${CFLAGS/-march=nocona/-march=i686}     &&
  export CFLAGS=${CFLAGS/-march=core2/-march=i686}      &&
  export CFLAGS=${CFLAGS/-march=athlon-fx/-march=i686}  &&
  export CFLAGS=${CFLAGS/-march=k8/-march=i686}         &&
  export CFLAGS=${CFLAGS/-march=opteron/-march=i686}    &&
  export CFLAGS=${CFLAGS/-march=em64t/-march=i686}
fi  &&

default_build
