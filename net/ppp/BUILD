create_group  ppp  &&
# Force a specific C standard to avoid build failures with newer compilers
case "$($CC --help)" in
  (*\ -std=*) CFLAGS+=' -std=gnu99';;
esac &&
default_build
