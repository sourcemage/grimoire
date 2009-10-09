create_account polkituser  &&

if [[ "$POLICYKIT_MAN" == "y" ]]; then
   OPTS="--enable-man-pages $OPTS"
else
   OPTS="--disable-man-pages $OPTS"
fi  &&

if [[ "$POLICYKIT_AFW" == "linux-pam" ]]; then
   OPTS="--with-authfw=pam $OPTS"
else
   OPTS="--with-authfw=$POLICYKIT_AFW $OPTS"
fi  &&

default_build