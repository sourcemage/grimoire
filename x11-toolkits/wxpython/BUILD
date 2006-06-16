persistent_read  wxgtk  WX_CONTRIB  WX_CONTRIB  &&

PYOPTS='MONOLITHIC=0 UNICODE=1' &&
for COMPONENT in $WX_CONTRIB; do
  PYOPTS="$PYOPTS BUILD_$(echo $COMPONENT | tr '[:lower:]' '[:upper:]')=1"
done &&
#if echo $OPTS | grep -q with-swig; then PYOPTS="$PYOPTS USE_SWIG=1"; fi &&

cd wxPython &&
python setup.py $PYOPTS build
