case "$CM_TESTS:$HOST" in
  (-DBUILD_TESTING=1:*-musl)
    message "${PROBLEM_COLOR}Disabling tests, these are incompatible with" \
	    "${SPELL_COLOR}musl$DEFAULT_COLOR"
    ;&
  (-DBUILD_TESTING=0:*)
    OPTS+=" -DTBB_TEST=off"
    ;;
esac &&

OPTS+=" -DTBB_STRICT=off" &&

default_build
