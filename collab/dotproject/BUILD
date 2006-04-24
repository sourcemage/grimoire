(
  prepare_install &&
  mkdir -p   /usr/share/$SPELL &&
  cp    -r . /usr/share/$SPELL/ &&
  if ! [ -f /usr/share/$SPELL/includes/config.php ]; then
    cp includes/config-dist.php /usr/share/$SPELL/includes/config.php
  fi
    
) >$C_FIFO 2>&1 && (

  echo "Please point your apache at /usr/share/$SPELL/"

)
