if [ -f /etc/profile.d/GNUstep.sh ];
then
    . /etc/profile.d/GNUstep.sh
else
    message "${ERROR_COLOR}Unable to find /etc/profile.d/GNUstep.sh"  &&
    message "Rebuild gnustep-make${DEFAULT_COLOR}"                    &&
    return 1
fi                                                                    &&

make_single
make                                                                  

if [ "$GMEMO" == "y" ];
then
    cd Bundles/Emoticon                                               &&
    make                                                              &&
    cd ../../
fi                                                                    &&

if [ "$GMFAC" == "y" ];
then
    cd Bundles/Face                                                   &&
    make                                                              &&
    cd ../../
fi                                                                    &&


if [ "$GMPGP" == "y" ];
then
    cd Bundles/PGP                                                    &&
    make                                                              &&
    cd ../../
fi                                                                    &&

make_normal
