#
# Disable -O compiler flags; see HISTORY entry from 2008-01-07
#
# cryptsetup wants the static lib
OPTS+=" --enable-static" &&
shopt -s extglob &&
CFLAGS="${CFLAGS//-O+([[:digit:]]|fast)/}" default_build &&
shopt -u extglob
