export GOROOT=${SOURCE_DIRECTORY}          &&
export GOROOT_FINAL=${TARGET_ROOT}/opt/go  &&
export GOARCH                              &&
export GOOS=linux                          &&
export GOBIN=${INSTALL_ROOT}/usr/bin/      &&
cd ${SOURCE_DIRECTORY}/src                 &&

check_tmp_noexec /tmp &&
./all.bash &&
check_tmp_noexec /tmp
