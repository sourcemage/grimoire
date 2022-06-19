cd src &&

make &&

if is_depends_enabled ${SPELL} docutils; then
  cd ../doc &&

  make SUFFIX=.py proot/man.1 &&

  cd ..
fi
