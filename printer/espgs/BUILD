# need a comma separated list
OPTS="--with-drivers=`echo ${ESPGS_PRINTERS} |sed "s/^ *//;s/ /,/g"`,FILES \
      --enable-dynamic ${OPTS}"  &&

make_single    &&
default_build  &&
make_normal
