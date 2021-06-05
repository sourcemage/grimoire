#sedit  "6690s/Screensaver/Screensaver Properties/"  po/es.po    &&

OPTS="--with-proc-interrupts $OPTS" &&
OPTS="--with-proc-oom $OPTS" &&
OPTS="--with-readdisplay $OPTS" &&
OPTS="--without-motif $OPTS" &&
if ! (is_depends_enabled $SPELL WEB-BROWSER); then
  OPTS="--without-browser $OPTS"
else
  OPTS="--with-browser=$(get_spell_provider $SPELL WEB-BROWSER) $OPTS"
fi &&
OPTS="$XSCSV_ROOT $XSCSV_LOCK $XSCSV_SETCAP $OPTS" &&

message "${MESSAGE_COLOR}OPTS=$OPTS${DEFAULT_COLOR}" &&

default_build
