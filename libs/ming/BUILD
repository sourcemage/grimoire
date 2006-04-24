make &&
if [[ "$MING_PY" == y ]]; then
  cd py_ext &&
  PYTHON_INC=$(python -c 'from distutils.sysconfig import get_python_inc; print get_python_inc()') &&
  PYTHON_LIB=$(python -c 'from distutils.sysconfig import get_python_lib; print get_python_lib()') &&
  sedit "s|PYINCDIR.*=.*|PYINCDIR=$PYTHON_INC|g" Makefile &&
  sedit "s|PYLIBDIR.*=.*|PYLIBDIR=${PYTHON_LIB%/*}|g" Makefile &&
  sedit 's|-lming|-L.. -lming|g' Makefile &&
  make mingcmodule.so &&
  cd ..
fi
