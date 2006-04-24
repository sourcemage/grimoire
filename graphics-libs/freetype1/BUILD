# Apply gcc 3.3 patch
bzcat  ${SOURCE_CACHE}/${SOURCE2}  |  patch  -p1  &&

./configure  --prefix=/usr    \
             --enable-static  \
             $OPTS            &&
make_single                   &&
make                          &&
make_normal
