cd Unix                                                                   &&
#  ./configure --prefix=/usr                                                 \
#              --host=pc-linux-gnu                                           \
#			  $OPTS                                                         &&
sedit "s!/usr/local/rtf2latex2e!${INSTALL_ROOT}/usr/share/rtf2latex2e!g" \
      Makefile.in  &&
./configure --prefix=${INSTALL_ROOT}/usr                                  \
            --host=pc-linux-gnu                                           \
            $OPTS                                                         &&
make
