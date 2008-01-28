# fix an install problem with 'install -s'
sed -i "s/-s$//" src/Makefile &&
make  &&


if is_depends_enabled $SPELL gtk+2; then
  make gui
fi
