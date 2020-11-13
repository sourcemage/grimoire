# This is such a basic system lib that existing .la
# files are very uncommon and confuse more than help.
default_build_configure &&
find . -name Makefile \
| xargs sed -i 's,^\(LIBTOOL[[:space:]]*=[[:space:]]*\),\1'"$GRIMOIRE"'/libtool-nola ,' &&
default_build_make
