cd $SOURCE_DIRECTORY &&
FB=$(get_spell_provider $SPELL FIREBIRD) &&
CPPFLAGS+=" -I/opt/$FB/include" &&
LDFLAGS+=" -L/opt/$FB/lib" &&
LDFLAGS+=' -lfbclient' &&
default_build

