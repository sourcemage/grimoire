sedit  "s/#error.*//g" source/optout.h  &&
sedit  "s/FILL IN NAME HERE........................./Source Mage GNU\/Linux, email graphics@sourcemage.org with bugs/g"  source/optout.h  &&
./configure  --prefix=/usr  COMPILED_BY="graphics@sourcemage.org"\
             $OPTS          &&
#fixup the config files so that megapov is usable.
sedit "s:/usr/local/share/:/usr/share/:g" povray.conf &&
sedit '$a\
Library_Path="/usr/share/povray-3.6/include"' povray.ini.in &&
make
