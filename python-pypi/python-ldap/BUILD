  sedit 's|^\(library_dirs[[:space:]]*=\).*$|\1 /usr/lib     /usr/lib/sasl2|'    setup.cfg &&
  sedit 's|^\(include_dirs[[:space:]]*=\).*$|\1 /usr/include /usr/include/sasl|' setup.cfg &&

  python  setup.py  build
