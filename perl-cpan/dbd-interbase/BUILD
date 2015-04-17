FBDEST=$INSTALL_ROOT/opt/firebird
answer()
{
cat <<EOF
$FBDEST/bin
$FBDEST/include
FBDEST/lib
localhost://$SOURCE_DIRECTORY/test.fdb
sysdba
masterkey
EOF
}

 bzcat $SPELL_DIRECTORY/Makefile.PL.bz2  >./Makefile.PL    &&
 perl  Makefile.PL                     &&
 make
