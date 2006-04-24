# always build with oss
OPTS="$OPTS --audio-oss"
# those lines remove the --audio-* switches and put them in the AUDIO array
# instead
# --audio-oss --audio-alsa will result in AUDIO=oss,alsa
local AUDIO="$(echo "$OPTS" | tr ' ' '\n' | grep audio)"
OPTS="$(echo "$OPTS" | tr ' ' '\n' | grep -v audio | tr '\n' ' ')"
AUDIO="$(echo "$AUDIO" | sed -e 's/--audio-//' | tr '\n' ',' | sed -e 's/,$//')"
OPTS="$OPTS --enable-audio=$AUDIO"
patch -p1 < $SCRIPT_DIRECTORY/gcc4.x.patch	&&
default_build
