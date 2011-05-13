local XCONV_PRG X_CONFIGDIR XCONFIGS                                    &&
XCONV_PRG="${SOURCE_DIRECTORY}/xsavers/migrate-xscreensaver-config.sh"  &&
X_CONFIGDIR="/usr/share/xscreensaver/config"                            &&

OPTS="${GSCREENSAVER_LOCKING} ${GSCREESAVER_DPMS} ${OPTS}"              &&
OPTS="${GSCREENSAVER_XIDLE} ${GSCREESAVER_VMODE} ${OPTS}"               &&
OPTS="${GSCREENSAVER_GAMMA} ${GSCREESAVER_XINERAMA} ${OPTS}"            &&

make_single                                                             &&
default_build                                                           &&
make_normal

if [ "${GSCREENSAVER_CONVERT}" == "y" ]; then
   if [ -e ${X_CONFIGDIR} ]; then
      cd ${SOURCE_DIRECTORY}                                            &&
      mkdir xsavers                                                     &&
      cd xsavers                                                        &&
      cp ${SOURCE_DIRECTORY}/data/*xscreensaver* ./                     &&
      for XCONFIGS in ${X_CONFIGDIR}/*.xml
      do
         ${XCONV_PRG} ${XCONFIGS}
      done                                                              &&
      cd ${SOURCE_DIRECTORY}
   else
	message "${PROBLEM_COLOR}No xscreensaver config files!${DEFAULT_COLOR}"
   fi
fi
