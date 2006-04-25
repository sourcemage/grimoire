message  "${MESSAGE_COLOR}If this fails, disable kernel module versioning{$DEFAULT_COLOR}"  &&

# First build static
make_single                                                            &&
make  static                                                           &&

# Have to remove for shared to build ...
rm  -f  src/svgalib_helper.h                                           &&
# Then build shared ...
make  shared                                                           &&

# Missing in some cases ...
ln  -s  libvga.so.${VERSION}  sharedlib/libvga.so                      &&
# Build lrmi and tools ...
make  LDFLAGS="-L../sharedlib"  textutils  lrmi  utils                 &&
# Build the gl stuff too
make  -C  gl                                                           &&
make  -C  gl  libvgagl.so.${VERSION}                                   &&
# Missing in some cases ...
ln  -s  libvgagl.so.${VERSION}  sharedlib/libvgagl.so                  &&
rm  -f  src/svgalib_helper.h                                           &&
make  -C  src  libvga.so.${VERSION}                                    &&
cp  -a  src/libvga.so.${VERSION}  sharedlib/                           &&
# Build threeDKit ...
make  LDFLAGS='-L../sharedlib'  -C  threeDKit  lib3dkit.a              &&
# Build demo's ...
make  CFLAGS="${CFLAGS} -I../gl -I../include" demoprogs                \
      LDFLAGS='-L../sharedlib'                                         &&

cd  kernel/svgalib_helper                                              &&
if  [[  "$(get_kernel_version)"  =~  "^2.6"  ]]; then
  message  "${MESSAGE_COLOR}Building for 2.6...${DEFAULT_COLOR}"       &&
  make
else
  message  "${MESSAGE_COLOR}Building for 2.4...${DEFAULT_COLOR}"       &&
  env  -u  ARCH                                                        \
  make  -f  Makefile.alt INCLUDEDIR="/usr/src/linux/include"           \
  clean  all
fi  &&
cd  -                                                                  &&

sedit 's/\(install: $(INSTALLAOUTLIB) \)installheaders \(.*\)/\1\2/g'  \
Makefile
