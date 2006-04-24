  unpack  $SOURCE2  ${MD5[1]}                             &&
  gunzip  -c  $SOURCE_CACHE/$SOURCE2  |  patch  -p1       &&

  # Removes some silly errors.
  sedit  '20,26 d'  include-glibc/netinet/in.h            &&

  make  TARGETS="tracepath tracepath6 traceroute6"
