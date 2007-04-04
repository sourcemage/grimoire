local PYCOMP                    &&
persistent_read  wxgtk  WX_CONTRIB  WX_CONTRIB  &&
message gtk=$WX_DEV             &&
message contrib=$WX_CONTRIB     &&
# turn of some default flags
PYOPTS="MONOLITHIC=0 UNICODE=1 BUILD_GLCANVAS=0 BUILD_STC=0 BUILD_GIZMOS=0" &&
# only build parts which are available for python
for PYCOMP in $WX_CONTRIB; do
  case $PYCOMP in
    glcanvas|stc|gizmos)
      PYOPTS="$PYOPTS BUILD_$(echo $PYCOMP | tr '[:lower:]' '[:upper:]')=1";;
   *);;
  esac
done  &&
message pyo=$PYOPTS  &&
persistent_add PYOPTS          &&
cd wxPython &&
python setup.py $PYOPTS build
