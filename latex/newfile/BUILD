TEXMF=`kpsetool -v '$TEXMFLOCAL'`   &&
persistent_add TEXMF                &&

latex   $SPELL.ins                  &&
latex   $SPELL.dtx                  &&
makeindex   -s gind.ist newfile     &&
latex   $SPELL.dtx
