# workaround a change in fltk 1.1.3
echo '#include <FL/x.H>' >> src/xine_iface_gui.h
patch -p0 < $SCRIPT_DIRECTORY/gcc-4.0.patch  &&
default_build
