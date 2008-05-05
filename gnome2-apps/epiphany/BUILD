
if [[ "${EPIPHANY_WEBKIT}" == "n" ]]; then
   case "$(get_spell_provider $SPELL GECKO)" in
      "firefox" )
         OPTS="${OPTS} --with-gecko=firefox"
      ;;
      "seamonkey" )
         OPTS="${OPTS} --with-gecko=seamonkey"
      ;;
      "xulrunner" )
         OPTS="${OPTS} --with-gecko=xulrunner"
      ;;
      * )
         OPTS="${OPTS} --with-gecko=mozilla"
      ;;
   esac
fi &&

# requires at least -O2 to not segfault on startup with gcc 4.0
if ! echo "$CFLAGS" | grep -q -- '-O3'; then
  CFLAGS="$CFLAGS -O2"      &&
  CXXFLAGS="$CXXFLAGS -O2"
fi &&

make_single   &&
default_build &&
make_normal
