# Disabling daemon as it fails to link during build
# Disabling appliacen as supermin needs to be ported to Sorcery for this to work
OPTS="--disable-daemon     \
      --disable-appliance  \
      --disable-golang     \
      --with-distro=SMGL   \
      $OPTS"               &&

# Disable checking KVM features: It's broken
export vmchannel_test=no  &&

default_build
