OPTS+=' -DQT_NO_PACKAGE_VERSION_INCOMPATIBLE_WARNING=TRUE' &&
OPTS+=' -DQT_NO_PACKAGE_VERSION_CHECK=TRUE' &&
OPTS+=' -DQT_BUILD_EXAMPLES_BY_DEFAULT=OFF' &&
OPTS+=' -DQT_GENERATE_SBOM=OFF' &&
# memory in GiB
MEM=`grep MemTotal /proc/meminfo|uniq|cut -d: -f2|cut -dk  -f1` &&
((MEM=$MEM/1024**2)) &&
JOBS=`echo "$MEM" / "1.6" | bc` &&
echo  $JOBS &&

export NINJAFLAGS="-j$JOBS -l$JOBS" &&

default_build
