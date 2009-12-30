cp  mf/skakbase.mf  mf/skakbrikker.mf mf/skakinf.mf  .          &&

for font in  mf/skak[123]*  mf/skakf*; do
    ( mf "\mode:=localfont; input $font" ) || return 1
done                                                            &&

for font in *.600gf; do
    gftopk $font || return 1
done
