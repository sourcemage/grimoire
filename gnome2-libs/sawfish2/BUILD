if [[ "${SAWFISH_IMAGE}" == "gdk-pixbuf" ]]; then
   OPTS="--enable-gdk-pixbuf ${OPTS}"
elif [[ "${SAWFISH_IMAGE}" == "imlib" ]]; then
   OPTS="--disble-gdk-pixbuf ${OPTS}"
fi  &&

if [[ "${SAWFISH_CAPPLET}" == "y" ]]; then
   OPTS="--enable-capplet ${OPTS}"
fi  &&

if [[ "${SAWFISH_WIDGETS}" == "y" ]]; then
   OPTS="--enable-gnome-widgets ${OPTS}"
fi  &&

make_single    &&
default_build  &&
make_normal
