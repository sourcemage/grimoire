if [ "${PAM_DOCS}" == "n" ]; then
   export  SGML2LATEX=no
fi

export PS2PDF=no

#autoconf                                             &&
./configure  --libdir=/usr/lib                       \
             --sbindir=/lib/security                 \
             --enable-securedir=/lib/security        \
             --enable-read-both-confs                \
             $OPTS                                   &&
sedit  "s/examples//"  Makefile                      &&
sedit  "s/read yes//"     conf/install_conf          &&
make_single  &&
make
