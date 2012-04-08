if [ $VBOXHARD == "n" ]; then
  OPTS="--disable-hardening $OPTS"
fi &&

OPTS="--disable-docs $OPTS" &&
./configure $OPTS  &&
source ./env.sh  &&
kmk all
