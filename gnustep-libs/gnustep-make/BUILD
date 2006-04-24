unset GNUSTEP_LOCAL_ROOT
unset GNUSTEP_HOST
unset GNUSTEP_MAKEFILES
unset GNUSTEP_NETWORK_ROOT
unset GNUSTEP_FLATTENED
unset GNUSTEP_HOST_OS
unset GNUSTEP_HOST_VENDOR
unset GNUSTEP_HOST_CPU
unset GNUSTEP_USER_ROOT
unset GNUSTEP_SYSTEM_ROOT
unset GNUSTEP_PATHLIST

./configure               \
    --prefix=/opt/GNUstep    #FSHS and openstep spec
    $OPTS                 &&

make                      &&

if [ "$DOCU" == "y" ]; 
then
    cd Documentation      &&
    make                  &&
    cd ../
fi 
