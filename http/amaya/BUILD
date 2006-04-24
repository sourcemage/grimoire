OPTS="$OPTS --with-dav" &&

# do the trick that forces configure to create __build/amaya directory
sedit 's|thotlib\/Makefile|thotlib\/Makefile amaya\/Makefile|g' configure &&

mkdir __build &&
cd __build &&
ln -fns ../configure configure &&

make_single &&
default_build &&
make_normal
