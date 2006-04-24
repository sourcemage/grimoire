#  unpack  $SOURCE2  ${MD5[1]}                         &&
#  gunzip  -c  $SOURCE_CACHE/$SOURCE2  |  patch  -p1   &&

  sedit  '20,26 d'  include-glibc/netinet/in.h        &&

  make  TARGETS="ping ping6"
