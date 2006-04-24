if [ "SELINUX" == "y" ]; then
  sedit  "s/HAVE_SELINUX=no/HAVE_SELINUX=yes/"   MCONFIG &&
  message "${MESSAGE_COLOR} SELINUX is  enabled ${DEFAULT_COLOR}"
fi

sedit  "s/HAVE_SLN=no/HAVE_SLN=yes/"   MCONFIG
sedit  "s/\$(OPT)//"                   MCONFIG
(

 patch  mount/pivot_root.c  <  $SCRIPT_DIRECTORY/pivot_root.c.diff  &&

 ./configure  --build=$BUILD           \
              --prefix=/usr            \
              $OPTS                    &&

  make                                 &&
  (
  if    spell_ok      util-linux
  then  dispel  --nosustain  util-linux
  fi                                   &&
  prepare_install
  ) &&
  make    install

) > $C_FIFO 2>&1  &&

if  !  [  -x  /etc/init.d/bootmisc.sh  ];  then
  cp  $SCRIPT_DIRECTORY/bootmisc.sh  /etc/init.d
fi
