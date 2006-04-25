if [ -f /etc/profile.d/GNUstep.sh ];
then
    . /etc/profile.d/GNUstep.sh
else
    message "${ERROR_COLOR}Unable to find /etc/profile.d/GNUstep.sh"  &&
    message "Rebuild gnustep-make${DEFAULT_COLOR}"                    &&
    return 1
fi                                                                    &&

cd Frameworks/PrefsModule

make                                                                  &&

cd ../../                                                             &&
