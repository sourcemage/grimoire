# don't install xinetd script
sedit "/XINETD=/D" configure            &&
# prevent install of init scripts
OPTS="$OPTS --without-rcdir"  &&
# choose languages
local CLIST                   &&
# remove leading blank,
CLIST=`echo ${CUPS_LANG} | sed "s/^ *//"`  &&

if [ $CLIST == none ];then
  OPTS="$OPTS --without-languages"
else
  OPTS="$OPTS --with-languages=\"$CLIST\" "
fi                            &&
default_build
