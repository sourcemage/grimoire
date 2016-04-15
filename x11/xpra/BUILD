# Hitting this through Cython:
# http://legacy.python.org/dev/peps/pep-3123/
CFLAGS+=" -fno-strict-aliasing" &&
# Warnings/strictness errors unfixable ... p.ex. via gtk2 dependency.
default_build_python --without-warn --without-strict $OPTS
