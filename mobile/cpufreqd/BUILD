
# disable lm_sensors support for 3.x branch to solve compilation issue
if [[ $(installed_version lm_sensors | cut -c 1) == 3 ]]; then
      OPTS="--disable-sensors $OPTS" 
fi  &&

default_build
