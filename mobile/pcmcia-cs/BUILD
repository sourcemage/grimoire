echo $(get_running_kernel_config CONFIG_PCCARD)
if [[ $(get_running_kernel_config CONFIG_PCCARD) != "y" ]] &&
   [[ $(get_running_kernel_config CONFIG_PCCARD) != "m" ]] &&
   [[ $(get_sorcery_kernel_config CONFIG_PCCARD) != "y" ]] &&
   [[ $(get_sorcery_kernel_config CONFIG_PCCARD) != "m" ]]
then
	message "${PROBLEM_COLOR}You don't have CONFIG_PCCARD enabled in your kernel${DEFAULT_COLOR}" &&
	return 1
fi

sedit "s:install_sysv$:true:"  etc/install-etc  &&
if [[ -d ${BUILD_DIRECTORY}/linux-$(uname -r) ]]
then
	KVER=$(uname -r)
	KDIR=${BUILD_DIRECTORY}/linux-$(uname -r)
elif [[ -d ${BUILD_DIRECTORY}/linux-$(get_kernel_version) ]]
then
	KVER=$(get_kernel_version)
	KDIR=${BUILD_DIRECTORY}/linux-$(get_kernel_version)
fi
if [[ ${KVER} == 2.6.* ]]
then 
  ./Configure --kernel=${KDIR} --srctree -n 
else 
  make    oldconfig
fi                 &&
make    all
