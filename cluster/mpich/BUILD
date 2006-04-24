patch  -p1  <  ${SCRIPT_DIRECTORY}/sysconfdir.patch  &&

#
# Fails to test rsh without this flag
#
if  [  -x  /usr/bin/rsh  ]
then
  OPTS="$OPTS  -rsh=/usr/bin/rsh"
fi  &&

./configure  --prefix=/usr            \
             --sysconfdir=/etc/mpich  \
             ${OPTS}                  &&
make
