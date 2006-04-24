cd acm/                                   &&
gzip -v *.acm                             &&
cd ../psf/                                &&
gzip -v *.psf                             &&
cd ../keymap/                             &&
sedit "s:macros1.inc:macros.inc:" cyr-urainian-ms-like2.cpp  &&
for f in *.cpp; do cpp -o `basename $f .cpp`.kmap $f; done  &&
gzip -v *.kmap                           &&
cd ../sfm/                               &&
gzip -v *.sfm                            &&
cd ../