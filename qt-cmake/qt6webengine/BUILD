if is_depends_enabled $SPELL nodejs-bin;then
  export PATH+=":/opt/nodejs/bin"
fi &&
# memory in GiB
MEM=`grep MemTotal /proc/meminfo|uniq|cut -d: -f2|cut -dk  -f1` &&
((MEM=$MEM/1024**2)) &&
JOBS=`echo "$MEM" / "1.6" | bc` &&
echo  $JOBS &&

export NINJAFLAGS="-j$JOBS -l$JOBS" &&

default_build
