OPTS="$OPTS --with-mysql-path=/usr" &&

if is_depends_enabled $SPELL libiodbc; then
    OPTS="$OPTS --with-iODBC=/usr"
fi &&

if is_depends_enabled $SPELL unixodbc; then
    OPTS="$OPTS --with-unixODBC=/usr"
fi &&

default_build
