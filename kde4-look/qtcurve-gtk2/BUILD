if [[ $QTCURVEGTK_KDEVER == "4.x" ]]; then
  export PATH="/usr/bin/qt4:/opt/bin:${PATH}"
fi &&

if spell_ok firefox || spell_ok firefox-bin && \
   [[ "$(installed_version firefox | cut -d. -f1-2)" == "3.0" ]] || \
   [[ "$(installed_version firefox-bin | cut -d. -f1-2)" == "3.0" ]]; then
  OPTS="-DQTC_NEW_MOZILLA=true"
fi
cmake_build
