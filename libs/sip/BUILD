sed -i "s/-O2//" specs/linux-g++ &&
# Need to use the proper selected python.
PYTHON=$(get_spell_provider_file $SPELL PYTHON '/usr/bin/python[0-9\.]*$') &&
$PYTHON ./configure.py CFLAGS_EXCEPTIONS_OFF=1 &&
make
