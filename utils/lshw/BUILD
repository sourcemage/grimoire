# fix an install problem with 'install -s'
sed -i "s/-s$//" src/Makefile &&
make  &&

#
## Remove this after is_depends_enabled is integrated to stable sorcery.
#
source  "$GRIMOIRE/is_depends_enabled.function"  &&

if is_depends_enabled $SPELL gtk+2; then
  make gui
fi
