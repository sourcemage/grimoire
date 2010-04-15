if [[ "${TRACKER_AC}" == "devicekit-power" ]]; then
  OPTS="--enable-devkit-power --disable-hal ${OPTS}"
else
  OPTS="--disable-devkit-power --enable-hal ${OPTS}"
fi &&

OPTS="--enable-video-extractor=${TRACKER_EXTRACTOR} \
      ${TRACKER_SEARCH_TOOL}                        \
      ${TRACKER_PREFERENCES}                        \
      ${TRACKER_STATUS}                             \
      ${TRACKER_EXPLORER}                           \
      ${TRACKER_SEARCH_BAR}                         \
      ${OPTS}"                                      &&

make_single    &&
default_build  &&
make_normal
