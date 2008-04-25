if [[ "$(get_spell_provider $SPELL  X11-SERVER)" != "xorg-server" ]]; then
   xmkmf
fi  &&

if [[ "$NAS_STARTSERVER" = 'y' ]] ; then
  make WORLDOPTS='-k CDEBUGFLAGS="$(CDEBUGFLAGS) -DSTARTSERVER"' World
else
  make World
fi
