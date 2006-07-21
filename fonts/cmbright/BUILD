TEXMF=`kpsetool -v '$TEXMFLOCAL'`               &&
persistent_add TEXMF                            &&
    
cd latex
latex $SPELL.ins                                &&
latex  --interaction batchmode   $SPELL.dtx     &&
latex  --interaction batchmode   $SPELL.dtx     &&
cd ..
