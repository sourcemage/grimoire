# build Compression Library and Proxy
for i in nxcomp nxproxy; do
  pushd $i; default_build; popd
done  &&

# build X11 Support Libraries and Agents
pushd nx-X11
  make World
popd  &&

# build Extended Compression Library
pushd nxcompext
  default_build
popd  &&

# build RFB Agent
pushd nxviewer
  xmkmf -a 
  cp -a /usr/X11R6/lib/libXp.so* ../nx-X11/exports/lib/
  make  
popd  &&

# build RDP Agent
pushd nxdesktop
  ./configure  &&
  make
popd
