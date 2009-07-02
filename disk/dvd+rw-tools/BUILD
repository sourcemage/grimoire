  sedit "s:/local::;s/-O2//" Makefile.m4	&&
  make                                          &&
  make rpl8                                     &&
  if [[ $(get_spell_provider $SPELL CD-BURN-UTILITY) != cdrtools ]]
  then
    make btcflash
  fi
