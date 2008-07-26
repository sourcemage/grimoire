echo  "gcc ${CFLAGS} -include /usr/include/errno.h"  >conf-cc  &&
echo  "gcc ${LDFLAGS}"                               >conf-ld  &&

make  &&

if  is_depends_enabled  $SPELL  groff;  then
  make man
fi
