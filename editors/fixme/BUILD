(

    TEXMF=`kpsetool -v '$TEXMFLOCAL'`                   &&

    latex $SPELL.ins                                    &&

    latex  --interaction batchmode   $SPELL.dtx         &&
    latex  --interaction batchmode   $SPELL.dtx         &&

    prepare_install                                     &&
    
    mkdir  -p  $TEXMF/tex/latex/$SPELL                  &&
    mkdir  -p  /usr/doc/$SPELL                          &&

    cp  $SPELL.sty  $TEXMF/tex/latex/$SPELL             &&

    cp  *.dvi       /usr/doc/$SPELL                     &&
    cp  *.el        /usr/doc/$SPELL                     &&
    cp  README*     /usr/doc/$SPELL                     &&
    cp  NEWS*       /usr/doc/$SPELL

) > $C_FIFO 2>&1
