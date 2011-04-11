# function installed_version () { echo 2.4.77; }  &&
if [[ $(installed_version "linux") == 2.4.* ]] ; then
        OPROFILEOPT="--with-linux=/usr/src/$(installed_version "linux")"
else
        OPROFILEOPT="--with-kernel-support"
fi   &&
OPTS="$OPTS $OPROFILEOPT" &&
disable_pic               &&
default_build
