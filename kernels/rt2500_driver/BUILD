if  [  "$RT_CVS"  ==  "y"  ] ; then
cd $SOURCE_DIRECTORY/rt2500/Module &&
make KERNDIR=/lib/modules/$(get_kernel_version)/build
else

cd $SOURCE_DIRECTORY/Module &&
make KERNDIR=/lib/modules/$(get_kernel_version)/build 
fi
