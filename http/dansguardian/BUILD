OPTS="$OPTS
  --sysvdir=/tmp/dansbuild
  --cgidir='$DANS_CGIDIR'
  --runas_usr=nobody
  --runas_grp=nogroup
  --piddir=/var/run
  --logrotatedir=/tmp/dansbuild
  --gccver=3
" &&

# Can't use default_build, ./configure fails with `--localstatedir' option
./configure $OPTS &&
make &&

rm -rf /tmp/dansbuild
