# Fix freetype2 casting for the first time
# freetype2 with harfbuzz support requires harfbuzz built with freetype2...
# see http://wiki.linuxfromscratch.org/blfs/ticket/5331#comment:2
if is_depends_enabled harfbuzz ${SPELL} && ! spell_ok ${SPELL}; then
  message "${WARNING_COLOR}Disabling harfbuzz for first cast${DEFAULT_COLOR}" &&
  list_remove  OPTS  '--with-harfbuzz=yes' &&
  OPTS="--with-harfbuzz=no ${OPTS}"
fi
default_build
