# there is no source/config.h in 3.6, so I don't know if this is needed for a different file.
#sedit  "s/DEFAULT_OUTPUT_FORMAT  't'/DEFAULT_OUTPUT_FORMAT  'n'/g" src/config.h  &&
sedit  "s/#error.*//g" source/optout.h  &&
sedit  "s/FILL IN NAME HERE........................./Source Mage GNU\/Linux, email graphics@sourcemage.org with bugs/g"  source/optout.h  &&
./configure  --prefix=/usr  COMPILED_BY="graphics@sourcemage.org"\
             $OPTS          &&
make
