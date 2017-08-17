# For use in INSTALL for Bug #16031
persistent_add gmp_old_version &&
gmp_old_version=$(installed_version ${SPELL}) &&

# needed by essential /bin/expr at least
OPTS="--libdir=$INSTALL_ROOT/lib $OPTS" &&
# gcc bug when running test?
CFLAGS=${CFLAGS/-O3/-O2}   &&
if [[ ${SMGL_COMPAT_ARCHS[1]} == alpha ]];then
  # Funny assembler error; I think it is the -mcpu=ev67 on my box
  # asm seems to need -Wa,-mev67 also; not sure if it's just that
  # generally, gmp knows well how to choose CFLAGS/CXXFLAGS
  unset CFLAGS CXXFLAGS
fi &&
default_build &&
# GMP authors suggest that the GMP binaries are not to be used
# if `make check' is not successful
if ! make check; then
  message "${ERROR_COLOR}The build environment on this machine produced non-working GMP, refrain from using GMP and dispel it!${DEFAULT_COLOR}"
fi
