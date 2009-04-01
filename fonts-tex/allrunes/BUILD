TEXMF=`kpsetool -v '$TEXMFLOCAL'`               &&
persistent_add TEXMF                            &&

latex $SPELL.ins                                &&
latex  --interaction batchmode   $SPELL.dtx     &&
latex  --interaction batchmode   $SPELL.dtx     &&
makeindex -s gind.ist $SPELL                    &&
latex  --interaction batchmode   $SPELL.dtx     &&
latex  --interaction batchmode   $SPELL.dtx
