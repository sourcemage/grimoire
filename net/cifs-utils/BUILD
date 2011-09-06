if [[ "$CIFS_UPCALL" == "y" ]]; then
    OPTS="$OPTS --enable-cifsupcall"
else
    OPTS="$OPTS --disable-cifsupcall"
fi &&

if [[ "$CIFS_CREDS" == "y" ]]; then
    OPTS="$OPTS --enable-cifscreds"
else
    OPTS="$OPTS --disable-cifscreds"
fi &&

if [[ "$CIFS_IDMAP" == "y" ]]; then
    OPTS="$OPTS --enable-cifsidmap"
else
    OPTS="$OPTS --disable-cifsidmap"
fi &&

default_build
