patch -p0 < $SCRIPT_DIRECTORY/cs.sc.patch &&
patch -p0 < $SCRIPT_DIRECTORY/cs.in.patch &&
scons  prefix=$INSTALL_ROOT/usr buildCsoundVST=0 buildJavaWrapper=0 usePortMIDI=0 gcc3opts=1 dynamicCsoundLibrary=1 buildStkOpcodes=0 $OPTS 
