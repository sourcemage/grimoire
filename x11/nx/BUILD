# build Compression Library and Proxy
for i in nxcomp nxcompshad nxproxy; do
  message "${MESSAGE_COLOR}building $i.${DEFAULT_COLOR}" &&
  pushd ${SOURCE_DIRECTORY}/$i      &&
  default_build &&
  popd
done  &&

# build X11 Support Libraries and Agents
message "${MESSAGE_COLOR}building nx-X11.${DEFAULT_COLOR}" &&
pushd ${SOURCE_DIRECTORY}/nx-X11  &&
  make_single &&
  FAST=1 make World WORLDOPTS="" MAKE="make" &&
  make_normal &&
popd  &&

# build Extended Compression Library
message "${MESSAGE_COLOR}building nxcompext.${DEFAULT_COLOR}" &&
pushd ${SOURCE_DIRECTORY}/nxcompext &&
  default_build &&
popd
