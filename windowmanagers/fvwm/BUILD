if [[ "${FVWM_RELEASE}" == "cvs" ]]; then
    aclocal                &&
    autoheader             &&
    automake --add-missing &&
    autoreconf
fi &&
OPTS="$OPTS $FVWM_OPTS"    &&
default_build
