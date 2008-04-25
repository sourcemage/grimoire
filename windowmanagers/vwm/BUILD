if [[ "$VIPER_WIDE" = 'y' ]]; then
  make wide &&
  if [[ "$VIPER_SYSMON" = 'y' ]]; then
    cd modules/sysmon &&
    make wide
  fi
else
  make &&
  if [[ "$VIPER_SYSMON" = 'y' ]]; then
    cd modules/sysmon &&
    make
  fi
fi
