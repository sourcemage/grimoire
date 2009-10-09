if [ $VBOXHARD == "n" ]; then
  OPTS="--disable-hardening $OPTS"
fi &&

./configure $OPTS  &&
source ./env.sh  &&
kmk all
