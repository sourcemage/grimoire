if [ "${PAM_DOCS}" == "n" ]; then
   export  SGML2LATEX=no
fi

export PS2PDF=no

OPTS="--enable-shared --enable-static $OPTS" &&

#autoconf                                             &&
./configure  --libdir=/lib                           \
             --sbindir=/lib/security                 \
             --enable-securedir=/lib/security        \
             --enable-read-both-confs                \
             $OPTS                                   &&
sedit  "s/examples//"  Makefile                      &&
sedit  "s/read yes//"     conf/install_conf          &&
make
