FIXES="s:extern char \*strstr();://extern char \*strstr();:g"

sedit  "$FIXES"  src/lrz.c
sedit  "$FIXES"  src/lsz.c

if  [  "$LRZSZ_STRIP_L"  ==  "y"  ]
then
  LRZSZ_TRANSFORM="--program-transform-name=s/l//"
else
  LRZSZ_TRANSFORM=""
fi

./configure  --build=$BUILD        \
             $LRZSZ_TRANSFORM      \
             --prefix=/usr         \
             --sysconfdir=/etc     \
             --localstatedir=/var  \
             $OPTS                 &&
make
