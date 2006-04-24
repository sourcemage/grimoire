  sedit 's:$(exec_prefix)/lib/uucp$:/usr/sbin:'         Makefile.in
  sedit 's:$(prefix)/man:$(prefix)/share/man:'          Makefile.in
  sedit 's:$(prefix)/info:$(prefix)/share/info:'        Makefile.in
  sedit 's:$(prefix)/conf/uucp:/etc/uucp:'              Makefile.in
  sedit 's:/usr/spool/uucp/Debug:/var/log/uucp/Debug:'  policy.h
  sedit 's:/usr/spool/uucp/Log:/var/log/uucp/Log:'      policy.h
  sedit 's:/usr/spool/uucp/Stats:/var/log/uucp/Stats:'  policy.h
  sedit 's:/usr/spool/uucp:/var/spool/uucp:'            policy.h

  ./configure $OPTS &&
  make
