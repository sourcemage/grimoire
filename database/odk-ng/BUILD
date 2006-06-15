cd $SOURCE_DIRECTORY/odkda2  &&
chmod u+x ./compile.sh       &&
./compile.sh                 &&
if [ "$ODK_PY"  == "y" ];then 
  cd $SOURCE_DIRECTORY/pyodk &&
  python setup.py build
fi
