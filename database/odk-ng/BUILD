cd odkda2                   &&
chmod u+x ./compile.sh     &&
./compile.sh               &&
if spell_ok g++; then
  cd odkda-cpp             &&
  chmod u+x ./compile.sh   &&
  ./compile.sh             &&
  cd ..
fi                         &&
if spell_ok mono; then
  cd odkda-sharp           &&
  chmod u+x ./compile.sh   &&
  ./compile.sh             &&
  cd ..
fi

