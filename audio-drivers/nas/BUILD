make World

if [[ "$NAS_STARTSERVER" = 'y' ]] ; then
  make WORLDOPTS='-k CDEBUGFLAGS="$(CDEBUGFLAGS) -DSTARTSERVER"' World
else
  make World
fi
