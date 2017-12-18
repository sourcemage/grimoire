# requires wbclient.h from samba/libwbclient
for opt in "--enable-cifsidmap" "--enable-cifsacl"; do
  if list_find "$CIFS_UTILS_OPTS" "$opt"; then
    message "${PROBLEM_COLOR}WARNING: option ${QUERY_COLOR}'$opt'${PROBLEM_COLOR} requires a non-existent spell, disabling it...${DEFAULT_COLOR}" &&

    list_remove CIFS_UTILS_OPTS "$opt"
  fi
done &&

OPTS="${CIFS_UTILS_OPTS} ${OPTS}" &&

default_build
