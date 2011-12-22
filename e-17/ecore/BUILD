if [ "$ECORE_CRYPTO" == "none" ]; then
   OPTS="--disable-gnutls --disable-openssl $OPTS"
fi  &&

if [[ $(get_spell_provider $SPELL OPENGL) ]] && is_depends_enabled $SPELL sdl; then
   ECORE_OPENGL_SDL="--enable-ecore-evas-opengl-sdl"
else
   ECORE_OPENGL_SDL="--disable-ecore-evas-opengl-sdl"
fi  &&

OPTS="$ECORE_FB $ECORE_IPV6 $ECORE_OPENGL_SDL $OPTS"  &&
OPTS="$ECORE_PTHREADS $ECORE_THREAD_SAFETY $OPTS"     &&

default_build
