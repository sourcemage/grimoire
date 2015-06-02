# fix build against system zlib
LDFLAGS="-L$INSTALL_ROOT/lib $LDFLAGS" &&

local PYTHON="$(get_spell_provider_file $SPELL PYTHON '/usr/bin/python[0-9\.]*$')" &&

$PYTHON setup.py build_py build_scripts &&
$PYTHON setup.py build_ext $OPTS
