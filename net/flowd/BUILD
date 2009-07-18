create_account flowd &&

default_build &&

if is_depends_enabled $SPELL perl; then
  cd Flowd-perl &&
  default_build_perl &&
  cd ..
fi &&

if is_depends_enabled $SPELL python; then
  default_build_python
fi
