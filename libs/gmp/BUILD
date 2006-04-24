default_build &&

# GMP authors suggest that the GMP binaries are not to be used
# if `make check' is not successful
if ! make check; then
  message "${ERROR_COLOR}The build environment on this machine produced non-working GMP, refrain from using GMP and dispel it!${DEFAULT_COLOR}"
fi
