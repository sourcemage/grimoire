# need a comma separated list
OPTS="--with-drivers=`echo ${GS_PRINTERS} |sed "s/^ *//;s/ /,/g"`,FILES \
      --enable-dynamic ${GS_OMNI} ${OPTS}"  &&

#make_single    &&
#default_build  &&
#make_normal
default_build &&

if  [[ "$GS_LIBGS" == y  ]];  then
  make  so
fi
