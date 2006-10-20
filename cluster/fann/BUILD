default_build &&

#
## Remove this after is_depends_enabled is integrated to stable sorcery.
#
source  "$GRIMOIRE/is_depends_enabled.function"  &&

if is_depends_enabled $SPELL python
then
  cd python &&
  python setup.py build &&
  cd ../
fi
