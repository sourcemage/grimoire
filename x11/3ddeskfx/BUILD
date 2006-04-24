(

  C_DIR="/etc/${SPELL}"

  prepare_install            &&
  cp  scripts/*  /usr/bin    &&
  mkdir  -p  ${C_DIR}        &&
  cp  config/*  ${C_DIR}
  # Can't copy these as Sorcery still doesn't
  # support filenames with spaces in them
  # cp  -r  shortcuts  ${C_DIR}

)  >  ${C_FIFO}  2>&1
