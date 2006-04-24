TEXMF=`kpsetool -v '$TEXMFLOCAL'`   &&
persistent_add TEXMF                &&

latex $SPELL.ins                    &&
latex $SPELL.dtx                    &&
latex $SPELL.dtx                    &&
makeindex -s gind.ist $SPELL        &&
latex $SPELL.dtx                    &&
latex $SPELL.dtx
