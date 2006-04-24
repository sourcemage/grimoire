mkdir -p temp                                                         &&
cd $SOURCE_DIRECTORY/groff                                            &&

if [ "$PS" == "y" ]; then
    groff -p -t -mm -Wall -M./tmac -Tps draft.mm > ../temp/fhs.ps
fi                                                                    &&
  
if [ "$DVI" == "y" ]; then
    groff -p -t -mm -Wall -M./tmac -Tdvi draft.mm > ../temp/fhs.dvi
fi                                                                    &&

if [ "$ASCII" == "y" ]; then
    groff -p -t -mm -Wall -M./tmac -Tascii draft.mm > ../temp/fhs.txt
fi                                                                    &&

if [ "$LATIN" == "y" ]; then
    groff -p -t -mm -Wall -M./tmac -Tascii draft.mm > ../temp/fhs.doc
fi
