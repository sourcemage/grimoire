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

default_build
