if is_depends_enabled $SPELL $(get_spell_provider $SPELL MYSQL); then
  make mysql
fi &&

if is_depends_enabled $SPELL postgresql; then
  make psql
fi &&

if is_depends_enabled $SPELL sqlite; then
  make sqlite3
fi
