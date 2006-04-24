(
# ac-query-parse.y  patch
message "${MESSAGE_COLOR} Aplying ac-query-parse patch ${DEFAULT_COLOR}"
gzip -d < $SCRIPT_DIRECTORY/ac-query-parse.patch.gz | patch -p0 -E

default_build
) > $C_FIFO 2>&1
