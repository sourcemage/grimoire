case $(get_spell_provider ${SPELL} GECKO) in
  seamonkey) OPTS="${OPTS} --with-mozilla=seamonkey"  ;;
  xulrunner) OPTS="${OPTS} --with-mozilla=xulrunner"  ;;
  xulrunner-bin) OPTS="${OPTS} --with-mozilla=xulrunner" ;;
  mozilla)   OPTS="${OPTS} --with-mozilla=mozilla"    ;;
  *)         OPTS="${OPTS} --disable-browser-plugins" ;;
esac &&

default_build
