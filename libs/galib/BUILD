 sedit  's:DESTDIR=/usr/local:DESTDIR=/usr:'  makevars   &&
 
 # remove the deprecated warnings.
 sedit  's:-Wall:-Wall -Wno-deprecated:'  makevars   &&
 
 # deal with a bad include statement in the examples code.
 sedit  '/#include <ga\/GARealGenome.C>/D' examples/ex21.C &&
 sedit  '/#include <ga\/GARealGenome.C>/D' examples/ex23.C   &&
 sedit  '/#include <ga\/GARealGenome.C>/D' examples/ex24.C   &&
 sedit  '/#include <ga\/GARealGenome.C>/D' examples/graphic/gaview.C   &&

 if [ "$GALIB_EXAMPLES" == "n" ]; then 
  sedit  's:cd examples; make::' makefile              
 fi                                                      &&

 make
