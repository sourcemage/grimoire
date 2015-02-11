create_account mdm &&

# Disable PAM helper if it was previously enabled when linux-pam is disabled
#if [[ "x${MDM_AUTH}" !=  "xlinux-pam" ]];  then
## Missing usermode package for `consolehelper` binary
  MDM_PAM_HELPER='--enable-console-helper=no'
#fi  &&

OPTS="${MDM_IPV6}                                         \
      --enable-authentication-scheme=${MDM_AUTH/linux-/}  \
      ${MDM_PAM_HELPER}                                   \
      ${OPTS}"                                            &&

default_build
