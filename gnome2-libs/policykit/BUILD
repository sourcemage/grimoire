create_account polkituser  &&
create_account polkitd     &&

if [[ "$POLICYKIT_AFW" == "linux-pam" ]]; then
   OPTS="--with-authfw=pam $OPTS"
else
   OPTS="--with-authfw=$POLICYKIT_AFW $OPTS"
fi  &&

default_build
