THERMAL_ZONES="$(ls /proc/acpi/thermal_zone/)"                  &&
THERMAL_ZONE="$(echo "$THERMAL_ZONES"|head -n1)"                         &&
BATTERIES="$(ls /proc/acpi/battery/)"                           &&
BATTONE="$(echo "$BATTERIES"|head -n1)"                         &&
BATTTWO="$(echo "$BATTERIES"|head -n2|tail -n1)"                &&
AC_ADAPTERS="$(ls /proc/acpi/ac_adapter/)"                      &&
AC_ADAPTER="$(echo "$AC_ADAPTERS"|head -n1)"                    &&

if ! [ -z ${THERMAL_ZONE} ]; then
  sedit "s/\/THM0\//\/${THERMAL_ZONE}\//g" ${SOURCE_DIRECTORY}/src/files.h
fi                                                              &&
if ! [ -z ${BATTONE} ]; then
  sedit "s/\/BAT0\//\/${BATTONE}\//g" ${SOURCE_DIRECTORY}/src/files.h
fi                                                              &&
if ! [ -z ${BATTTWO} ]; then
  sedit "s/\/BAT1\//\/${BATTTWO}\//g" ${SOURCE_DIRECTORY}/src/files.h
fi                                                              &&
if ! [ -z ${AC_ADAPTER} ]; then
  sedit "s/\/AC\//\/${AC_ADAPTER}\//g" ${SOURCE_DIRECTORY}/src/files.h
fi                                                              &&

default_build
