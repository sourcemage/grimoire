[[  $CROSS_INSTALL  ==  on  ]]  &&  OPTS="$OPTS  -host  ${HOST}"

./configure  -prefix  ${INSTALL_ROOT}/usr            \
             -mandir  ${INSTALL_ROOT}/usr/share/man  \
             ${OPTS}                                 &&

make_single                                          &&
make  world                                          &&
make  opt                                            &&
make  opt.opt                                        &&
make_normal
