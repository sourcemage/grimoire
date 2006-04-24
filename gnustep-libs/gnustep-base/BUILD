if [ -f /etc/profile.d/GNUstep.sh ];
then
    . /etc/profile.d/GNUstep.sh
else
    message "${ERROR_COLOR}Unable to find /etc/profile.d/GNUstep.sh"
    message "Rebuild gnustep-make${DEFAULT_COLOR}"
    exit 1
fi                                                                    &&

./configure                                                           \
    $OPTS                                                             &&

make

if [ "$DOCU" == "y" ]; 
then
    PATH=$PATH:`pwd`/Tools/shared_obj                                 &&
    LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/Source/shared_obj          &&
    cd Documentation                                                  &&
    make_single                                                       &&
    make                                                              &&
    make_normal                                                       &&
    cd ../
fi

