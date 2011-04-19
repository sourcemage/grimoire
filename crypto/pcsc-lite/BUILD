if [[ $PCSC_DEVICE_ACCESS != udev ]]; then
  OPTS="--disable-libudev $OPTS"
fi &&
if [[ $PCSC_DEVICE_ACCESS != libusb ]]; then
  OPTS="--disable-libusb $OPTS"
fi &&

make_single    &&
default_build  &&
make_normal
