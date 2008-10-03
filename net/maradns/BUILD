./configure $MARADNS_AUTHONLY &&

# Always nagging about no jobserver
make_single &&

if list_find "$MARADNS_AUTHONLY" "--authonly"; then
    make FLAGS="$CFLAGS -Wall -DSELECT_PROBLEM -DAUTHONLY"
else
    make FLAGS="$CFLAGS -Wall -DSELECT_PROBLEM"
fi
