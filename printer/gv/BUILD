cp  $SCRIPT_DIRECTORY/gv.man  doc
cp  $SCRIPT_DIRECTORY/gv.man  source

# I'm not sure why this is here -- Jason
#  perl  -i  -pe  's/ComplexProgramTarget/ComplexProgramTargetNoMan/'  source/Imakefile  &&

xmkmf            &&
cd  source       &&
./inc_2lit       &&
cd  -            &&
make  Makefiles  &&
make
