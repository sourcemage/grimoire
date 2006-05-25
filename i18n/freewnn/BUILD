if [[ $UNSAFE == "y" ]]; then
  OPTS="$OPTS --enable-unsafe-path"
else
  OPTS="$OPTS --disable-unsafe-path"
fi &&
create_group wnn                                 &&
create_account wnn /dev/null /bin/false wnn      &&
default_build
