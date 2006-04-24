default_pre_build &&

# sanitize user input
declare -r HAVP_PORT2=${HAVP_PORT//[^0-9]/} &&
declare -r HAVP_INADDR2=${HAVP_INADDR//[^0-9\.]/} &&
declare -r HAVP_TMP2=${HAVP_TMP%/} &&

if [[ -z "$HAVP_TMP2" ]]; then
  message "Partition for temporary files must not be empty" &&
  false
else
  cd $SOURCE_DIRECTORY &&

  if [[ -n "$HAVP_PORT2" ]]; then
    sedit "s|define PORT [0-9]\+|define PORT $HAVP_PORT2|g" havp/default.h
  fi &&

  if [[ -n "$HAVP_INADDR2" ]]; then
    sedit "s|define BIND_ADDRESS .\+|define BIND_ADDRESS \"$HAVP_INADDR2\"|g" havp/default.h
  fi &&

  sedit "s|/tmp/virus/havp-XXXXXX|$HAVP_TMP2/scan-XXXXXX|g" havp/default.h
fi
