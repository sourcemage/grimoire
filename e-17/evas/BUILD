if [[ $(get_spell_provider $SPELL OPENGL) ]] && is_depends_enabled $SPELL sdl; then
  EVAS_GL_SDL="--enable-gl-sdl --enable-sdl-primitive"
else
  EVAS_GL_SDL="--disable-gl-sdl --disable-sdl-primitive"
fi  &&

OPTS="$EVAS_GL_SDL $EVAS_PMAPS $OPTS"  &&

if  [  "$EVAS_BUFFER"  =  "y"  ];  then
  OPTS="--enable-buffer  $OPTS"
else
  OPTS="--disable-buffer  $OPTS"
fi  &&

if  [  "$EVAS_SCALE_SAMPLE"  =  "y"  ];  then
  OPTS="--enable-scale-sample  $OPTS"
else
  OPTS="--disable-scale-sample  $OPTS"
fi  &&

if  [  "$EVAS_SCALE_SMOOTH"  =  "y"  ];  then
  OPTS="--enable-scale-smooth  $OPTS"
else
  OPTS="--disable-scale-smooth  $OPTS"
fi  &&

if  [  "$EVAS_YUV"  =  "y"  ];  then
  OPTS="--enable-convert-yuv  $OPTS"
else
  OPTS="--disable-convert-yuv  $OPTS"
fi  &&

if  [  "$EVAS_DITHER_MASK"  =  "y"  ];  then
  OPTS="--enable-small-dither-mask  $OPTS"
else
  OPTS="--disable-small-dither-mask  $OPTS"
fi  &&

if  [  "$EVAS_ASYNC_RENDER" = "y"   ];  then
  OPTS="--enable-async-render $OPTS"
fi &&

if is_depends_enabled $SPELL fribidi && is_depends_enabled fribidi glib2 ; then
   CFLAGS="$CFLAGS -I/usr/include/glib-2.0"
fi  &&

if [[ "x${EVAS_X11XCB}" == "xnone" ]];  then
  OPTS="--disable-software-xlib \
        --without-x \
        --disable-software-xcb \
        --disable-async-events \
         $OPTS"
fi  &&

# We don't have wayland spells yet, http://wayland.freedesktop.org/
OPTS="--disable-wayland-shm --disable-wayland-egl $OPTS" &&

CFLAGS+=" -I/usr/lib/glib-2.0/include -I/usr/include/glib-2.0" default_build
