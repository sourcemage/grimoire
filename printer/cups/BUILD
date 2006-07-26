# don't install xinetd script
sedit "/XINETD=/D" configure            &&
# prevent install of init scripts
OPTS="--without-rcdir  $OPTS"  &&
# choose languages
local CLIST                   &&
# remove leading blank,
CLIST=`echo ${CUPS_LANG} | sed "s/^ *//"`  &&

if [ $CLIST == none ];then
  OPTS="--without-languages $OPTS"
else
  OPTS="--with-languages=\"$CLIST\" $OPTS"
fi                            &&
default_build
