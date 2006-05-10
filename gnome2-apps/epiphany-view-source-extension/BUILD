if spell_ok firefox; then
   OPTS="$OPTS --with-mozilla=firefox"
else
   OPTS="$OPTS --with-mozilla=mozilla"
fi &&

OPTS="$OPTS --with-epiphany-version=`installed_version  epiphany|cut -d. -f1,2`"  &&

default_build
