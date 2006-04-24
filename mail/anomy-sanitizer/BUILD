(

  sedit 's:$ENV{"ANOMY"} . "/bin":"/usr/lib":' bin/sanitizer.pl           &&
  sedit 's:$ENV{"ANOMY"} . "/bin":"/usr/lib":' bin/simplify.pl            &&
  prepare_install                                                         &&
  cp -a -r  $SOURCE_DIRECTORY/bin/Anomy /usr/lib/                         &&
  cp -a     $SOURCE_DIRECTORY/bin/*.pl  /usr/sbin/                        &&
  chown  -R root.root        /usr/sbin/sanitizer.pl /usr/sbin/simplify.pl &&
  chmod  0555                /usr/sbin/sanitizer.pl /usr/sbin/simplify.pl
) > $C_FIFO 2>&1
