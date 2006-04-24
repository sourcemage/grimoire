  sedit  "s:\=pentium4:\=${ARCHITECTURE}:"  Makefile      &&
  sedit  "s:-O3 -march=\$(MARCH):${CXXFLAGS}:"  Makefile  &&
  for i in `grep libevocosm\/ * | cut -d: -f1 | uniq`
  do
    sedit  's:libevocosm/::g'  $i
  done                                                    &&

  make  clean                 &&
  make                        &&
  make  docs
