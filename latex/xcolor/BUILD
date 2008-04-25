latex xcolor.ins && 
latex xcolor.dtx && 
latex xcolor.dtx && 
makeindex -s gind.ist xcolor.idx && 
latex xcolor.dtx && 
latex xcolor.dtx &&
dvipdf xcolor.dvi &&
for texfile in xcolor[1234].tex; do
    latex $texfile &&
    latex $texfile
done &&
pdflatex xcolor1.tex
