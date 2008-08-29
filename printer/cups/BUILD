# prevent install of init scripts
OPTS="--without-rcdir $OPTS"  &&

# set language options
if [[ $EXTRA_LANG == n ]]; then
  OPTS="--without-languages $OPTS"
else
  if [[ $CUPS_LANG == all ]]; then
    OPTS="--with-languages $OPTS"
  else
    OPTS="--with-languages=$CUPS_LANG $OPTS"
  fi
fi &&

default_build
