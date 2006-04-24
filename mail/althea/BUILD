(

  sedit  's!local/!!'  Makefile  &&
  sedit  "s/^DEBUGFLAGS =/& $CFLAGS -Wno-deprecated/"  Makefile  &&
  sedit  's/-g//'  Makefile  &&
  sedit  '/-r Documentation/d'  Makefile  &&

  sedit  '8s/^$/using namespace std;/'  tolower.h  &&
  sedit  '11s/^$/using namespace std;/'  MIME.h  &&
  sedit  '94s/unsigned//'  MIME.cpp  &&

  make  &&
  prepare_install  &&
  make  install

)  >  $C_FIFO  2>&1
