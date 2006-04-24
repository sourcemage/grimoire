answer()
{
cat <<EOF
/usr/firebird/bin
/usr/firebird/include
/usr/firebird/lib
localhost://$SOURCE_DIRECTORY/test.fdb
sysdba
masterkey
EOF
}
#  chgrp firebird $SOURCE_DIRECTORY              &&
#  chmod g+rw $SOURCE_DIRECTORY                  &&
#  sedit \
#"298,304d;s#/opt/fire#/usr/fire#;s#=> ''#=> '$CFLAGS'#" \
#	Makefile.PL				&&
#  answer | perl  Makefile.PL  			&&
#  make               				&&
#  make test

 bzcat $SPELL_DIRECTORY/Makefile.PL.bz2  >./Makefile.PL    &&
 perl  Makefile.PL                     &&

  make
