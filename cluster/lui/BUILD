perl Makefile.PL PREFIX=/usr  &&

sedit "s/\/usr\/share\/man/\/usr\/man/g"                       Makefile  &&
sedit "s/\$(PREFIX)\/templates/\/usr\/share\/lui\/templates/"  Makefile  &&
sedit "s/\$(PREFIX)\/share/\/usr\/share\/lui\/share/"          Makefile  &&
sedit "s/\$(PREFIX)\/samples/\/usr\/share\/lui/"               Makefile  &&
sedit "s/\$(PREFIX)\/doc/\/usr\/doc\/lui/"                     Makefile  &&

make        &&
make  test
