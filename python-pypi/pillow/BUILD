OPTS="${PILLOW_OPTS} ${OPTS}" &&

# fix build against system zlib
LDFLAGS="-L$INSTALL_ROOT/lib $LDFLAGS" &&

python3 setup.py build_py build_scripts &&
python3 setup.py build_ext $OPTS
