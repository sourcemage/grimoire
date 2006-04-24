# replace the default file
cp -f "$SCRIPT_DIRECTORY/global.properties" scite/src/SciTEGlobal.properties &&

cd scintilla/gtk   &&
make GTK2=1        &&
cd ../../scite/gtk &&
make GTK2=1
