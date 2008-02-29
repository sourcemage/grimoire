#
# We can't do this with DEPENDS as we can only
# enable one at a time
#
if  [  "$ENTRANCE_AUTH"  ==  "pam"  ];  then
  OPTS="--with-auth-mode=pam  \
        $OPTS"
else
  OPTS="--with-auth-mode=shadow  \
        $OPTS"
fi  &&

default_build
