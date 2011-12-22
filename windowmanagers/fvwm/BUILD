if [[ "${FVWM_BRANCH}" == "scm" ]]; then
    aclocal                &&
    autoheader             &&
    automake --add-missing &&
    autoreconf
fi &&
OPTS="$OPTS $FVWM_OPTS"    &&
default_build
