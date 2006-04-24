(
  sedit 's:$(exec_prefix)/lib/uucp$:/usr/sbin:'         Makefile.in
  sedit 's:$(prefix)/man:$(prefix)/share/man:'          Makefile.in
  sedit 's:$(prefix)/info:$(prefix)/share/info:'        Makefile.in
  sedit 's:$(prefix)/conf/uucp:/etc/uucp:'              Makefile.in
  sedit 's:/usr/spool/uucp/Debug:/var/log/uucp/Debug:'  policy.h
  sedit 's:/usr/spool/uucp/Log:/var/log/uucp/Log:'      policy.h
  sedit 's:/usr/spool/uucp/Stats:/var/log/uucp/Stats:'  policy.h
  sedit 's:/usr/spool/uucp:/var/spool/uucp:'            policy.h

  ./configure $OPTS &&
  make              &&
  prepare_install   &&
  make    install

) > $C_FIFO 2>&1  &&

(
  mkdir -p /etc/uucp                      &&
  mkdir -p /var/log/uucp                  &&
  chown uucp.uucp  /var/log/uucp          &&
  mkdir -p /var/spool/uucp                &&
  chown uucp.uucp  /var/spool/uucp        &&
  mkdir -p /var/spool/uucppublic          &&
  chown uucp.uucp  /var/spool/uucppublic  &&

  mkdir -p /usr/doc/uucp/sample           &&
  cp  sample/*  /usr/doc/uucp/sample      &&

  mkdir -p /usr/doc/uucp/contrib          &&
  cp  contrib/*  /usr/doc/uucp/contrib
)
