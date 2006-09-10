# don't install xinetd script
sedit "/XINETD=/D" configure            &&
# prevent install of init scripts
OPTS="$OPTS --without-rcdir"  &&
# Set language options
#local CLIST                   &&
# remove leading blank
#CLIST=`echo ${CUPS_LANG} | sed "s/^ *//"`  &&
if [ ${EXTRA_LANG} == "n" ]; then
  OPTS="--without-languages $OPTS"
else
  if [ ${CUPS_LANG} == "all" ]; then
      OPTS="--with-languages $OPTS"
  else
      OPTS="--with-languages=$CUPS_LANG $OPTS"
  fi
fi  &&
default_build
 
