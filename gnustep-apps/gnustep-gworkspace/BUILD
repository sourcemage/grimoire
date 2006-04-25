if [ -f /etc/profile.d/GNUstep.sh ];
then
    . /etc/profile.d/GNUstep.sh
else
    message "${ERROR_COLOR}Unable to find /etc/profile.d/GNUstep.sh"  &&
    message "Rebuild gnustep-make${DEFAULT_COLOR}"                    &&
    return 1
fi                                                                    &&

./configure $OPTS                                                     &&

make_single                                                           &&
make                                                                  &&

if [ "$GWREM" == "y" ];
then
    cd GWRemote                                                       &&
    make                                                              &&
    cd ../
fi                                                                    &&

if [ "$GWCLP" == "y" ];
then
    cd ClipBook                                                       &&
    make                                                              &&
    cd ../
fi                                                                    &&

make_normal                                                           
