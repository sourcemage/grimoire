if [[ -f /etc/profile.d/qt.sh ]]; then
  . /etc/profile.d/qt.sh
fi                                                 &&

OPTS="-DCMAKE_CXX_FLAGS=-DQT_THREAD_SUPPORT -DKDE3_INCLUDE_DIR=/usr/include/kde3 $OPTS" &&
cmake_build
