OPTS="$TINYPROXY_OPTS $OPTS" &&

default_build &&

# don't trash config file in /etc
sed -i "{N;s:\n\tetc \\\::}" Makefile.am
