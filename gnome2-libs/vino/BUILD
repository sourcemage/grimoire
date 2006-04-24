if [ "$HTTPSERVER" == "y" ]; then
   OPTS="$OPTS --enable-http-server"
else
   OPTS="$OPTS --disable-http-server"
fi  &&

if [ "$SESSIONMAN" == "y" ]; then
   OPTS="$OPTS --enable-session-support"
else
   OPTS="$OPTS --disable-session-support"
fi  &&

default_build
