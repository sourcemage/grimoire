if [ -f /etc/profile.d/GNUstep.sh ];
then
    . /etc/profile.d/GNUstep.sh
else
    message "${ERROR_COLOR}Unable to find /etc/profile.d/GNUstep.sh"  &&
    message "Rebuild gnustep-make${DEFAULT_COLOR}"                    &&
    return 1
fi                                                                    &&

./configure --enable-graphics=xlib --with-name=xlib                   \
$OPTS                                                                 &&
make                                                              

if [ "$GNUSTEP_BUILD_DOC" == "y" ]; 
then
    cd Documentation                                                  &&
    make_single                                                       &&
    make                                                              &&
    make_normal                                                       &&
    cd ../
fi                                                                    &&
