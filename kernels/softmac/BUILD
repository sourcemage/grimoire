if [[ $(get_sorcery_kernel_config CONFIG_IEEE80211) == "y" ||
      $(get_sorcery_kernel_config CONFIG_IEEE80211) == "m" ]]
then
  make  KDIR=/lib/modules/$(get_kernel_version)/build
else
  message "${MESSAGE_COLOR}Kernel $(get_kernel_version) needs to have"     \
          "CONFIG_IEEE80211 subsystem built in or module${DEFAULT_COLOR}"  &&
  return  1
fi
