create_account sfs  &&

OPTS="$OPTS --with-gmp=/usr"  &&
if  [ "$SFS_CVS" == "y" ];  then
  ./setup
fi  &&
# needed for gcc 3.3
sed -i  "s:-Werror::"  configure  &&
default_build
