unset  CFLAGS            &&
unset  CXXFLAGS          &&
export  CFLAGS="-Os"     &&

# Begin setting up OPTS based on responses from CONFIGURE

if  [  "$GRUB_EXT2"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ext2fs"
else
  OPTS="$OPTS  --disable-ext2fs"
fi  &&

if  [  "$GRUB_FAT"  =  "y"  ];  then
  OPTS="$OPTS  --enable-fat"
else
  OPTS="$OPTS  --disable-fat"
fi  &&

if  [  "$GRUB_FFS"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ffs"
else
  OPTS="$OPTS  --disable-ffs"
fi  &&

if  [  "$GRUB_MINIX"  =  "y"  ];  then
  OPTS="$OPTS  --enable-minix"
else
  OPTS="$OPTS  --disable-minix"
fi  &&

if  [  "$GRUB_REISER"  =  "y"  ];  then
  OPTS="$OPTS  --enable-reiserfs"
else
  OPTS="$OPTS  --disable-reiserfs"
fi  &&

if  [  "$GRUB_REISER4"  =  "y"  ];  then
  OPTS="$OPTS  --enable-reiser4"
else
  OPTS="$OPTS  --disable-reiser4"
fi  &&

if  [  "$GRUB_JFS"  =  "y"  ];  then
  OPTS="$OPTS  --enable-jfs"
else
  OPTS="$OPTS  --disable-jfs"
fi  &&

if  [  "$GRUB_XFS"  =  "y"  ];  then
  OPTS="$OPTS  --enable-xfs"
else
  OPTS="$OPTS  --disable-xfs"
fi  &&

if  [  "$GRUB_VSTA"  =  "y"  ];  then
  OPTS="$OPTS  --enable-vstafs"
else
  OPTS="$OPTS  --disable-vstafs"
fi  &&

if  [  "$GRUB_GZIP"  =  "y"  ];  then
  OPTS="$OPTS  --enable-gunzip"
else
  OPTS="$OPTS  --disable-gunzip"
fi  &&

if  [  "$GRUB_MD5"  =  "y"  ];  then
  OPTS="$OPTS  --enable-md5-password"
else
  OPTS="$OPTS  --disable-md5-password"
fi  &&

if  [  "$GRUB_PACKET"  =  "y"  ];  then
  OPTS="$OPTS  --enable-packet-retransmission"
else
  OPTS="$OPTS  --disable-packet-retransmission"
fi  &&

if  [  "$GRUB_PCI"  =  "y"  ];  then
  OPTS="$OPTS  --enable-pci-direct"
else
  OPTS="$OPTS  --disable-pci-direct"
fi  &&

if  [  "$GRUB_3C503"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c503"
else
  OPTS="$OPTS  --disable-3c503"
fi  &&

if  [  "$GRUB_3C503_SH"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c503-shmem"
else
  OPTS="$OPTS  --disable-3c503-shmem"
fi  &&

if  [  "$GRUB_3C503_AUI"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c503-aui"
else
  OPTS="$OPTS  --disable-3c503-aui"
fi  &&

if  [  "$GRUB_3C507"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c507"
else
  OPTS="$OPTS  --disable-3c507"
fi  &&

if  [  "$GRUB_3C509"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c509"
else
  OPTS="$OPTS  --disable-3c509"
fi  &&

if  [  "$GRUB_3C529"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c529"
else
  OPTS="$OPTS  --disable-3c529"
fi  &&

if  [  "$GRUB_3C595"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c595"
else
  OPTS="$OPTS  --disable-3c595"
fi  &&

if  [  "$GRUB_3C90x"  =  "y"  ];  then
  OPTS="$OPTS  --enable-3c90x"
else
  OPTS="$OPTS  --disable-3c90x"
fi  &&

if  [  "$GRUB_CS89x0"  =  "y"  ];  then
  OPTS="$OPTS  --enable-cs89x0"
else
  OPTS="$OPTS  --disable-cs89x0"
fi  &&

if  [  "$GRUB_DAVICOM"  =  "y"  ];  then
  OPTS="$OPTS  --enable-davicom"
else
  OPTS="$OPTS  --disable-davicom"
fi  &&

if  [  "$GRUB_DEPCA"  =  "y"  ];  then
  OPTS="$OPTS  --enable-depca"
else
  OPTS="$OPTS  --disable-depca"
fi  &&

if  [  "$GRUB_EEPRO10"  =  "y"  ];  then
  OPTS="$OPTS  --enable-eepro"
else
  OPTS="$OPTS  --disable-eepro"
fi  &&

if  [  "$GRUB_EEPRO100"  =  "y"  ];  then
  OPTS="$OPTS  --enable-eepro100"
else
  OPTS="$OPTS  --disable-eepro100"
fi  &&

if  [  "$GRUB_EPIC100"  =  "y"  ];  then
  OPTS="$OPTS  --enable-epic100"
else
  OPTS="$OPTS  --disable-epic100"
fi  &&

if  [  "$GRUB_SMC9000"  =  "y"  ];  then
  OPTS="$OPTS  --enable-smc9000"
else
  OPTS="$OPTS  --disable-smc9000"
fi  &&

if  [  "$GRUB_EXOS205"  =  "y"  ];  then
  OPTS="$OPTS  --enable-exos205"
else
  OPTS="$OPTS  --disable-exos205"
fi  &&

if  [  "$GRUB_NI5010"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ni5010"
else
  OPTS="$OPTS  --disable-ni5010"
fi  &&

if  [  "$GRUB_NI5210"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ni5210"
else
  OPTS="$OPTS  --disable-ni5210"
fi  &&

if  [  "$GRUB_NI6510"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ni6510"
else
  OPTS="$OPTS  --disable-ni6510"
fi  &&

if  [  "$GRUB_LANCE"  =  "y"  ];  then
  OPTS="$OPTS  --enable-lance"
else
  OPTS="$OPTS  --disable-lance"
fi  &&

if  [  "$GRUB_NE"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ne"
else
  OPTS="$OPTS  --disable-ne"
fi  &&

if  [  "$GRUB_NE2000"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ns8390"
else
  OPTS="$OPTS  --disable-ns8390"
fi  &&

if  [  "$GRUB_NE2100"  =  "y"  ];  then
  OPTS="$OPTS  --enable-ne2100"
else
  OPTS="$OPTS  --disable-ne2100"
fi  &&

if  [  "$GRUB_NATSEMI"  =  "y"  ];  then
  OPTS="$OPTS  --enable-natsemi"
else
  OPTS="$OPTS  --disable-natsemi"
fi  &&

if  [  "$GRUB_WD"  =  "y"  ];  then
  OPTS="$OPTS  --enable-wd"
else
  OPTS="$OPTS  --disable-wd"
fi  &&

if  [  "$GRUB_OTULIP"  =  "y"  ];  then
  OPTS="$OPTS  --enable-otulip"
else
  OPTS="$OPTS  --disable-otulip"
fi  &&

if  [  "$GRUB_TULIP"  =  "y"  ];  then
  OPTS="$OPTS  --enable-tulip"
else
  OPTS="$OPTS  --disable-tulip"
fi  &&

if  [  "$GRUB_RTL8139"  =  "y"  ];  then
  OPTS="$OPTS  --enable-rtl8139"
else
  OPTS="$OPTS  --disable-rtl8139"
fi  &&

if  [  "$GRUB_SIS900"  =  "y"  ];  then
  OPTS="$OPTS  --enable-sis900"
else
  OPTS="$OPTS  --disable-sis900"
fi  &&

if  [  "$GRUB_SK_G16"  =  "y"  ];  then
  OPTS="$OPTS  --enable-sk-g16"
else
  OPTS="$OPTS  --disable-sk-g16"
fi  &&

if  [  "$GRUB_TIARA"  =  "y"  ];  then
  OPTS="$OPTS  --enable-tiara"
else
  OPTS="$OPTS  --disable-tiara"
fi  &&

if  [  "$GRUB_VIARHINE"  =  "y"  ];  then
  OPTS="$OPTS  --enable-via-rhine"
else
  OPTS="$OPTS  --disable-via-rhine"
fi  &&

if  [  "$GRUB_W89C840"  =  "y"  ];  then
  OPTS="$OPTS  --enable-w89c840"
else
  OPTS="$OPTS  --disable-w89c840"
fi  &&

if  [  "$GRUB_COMP_FIX"  =  "y"  ];  then
  OPTS="$OPTS  --enable-compex-rl2000-fix"
else
  OPTS="$OPTS  --disable-compex-rl2000-fix"
fi  &&

if  [  "$GRUB_DISKLESS"  =  "y"  ];  then
  OPTS="$OPTS  --enable-diskless"
else
  OPTS="$OPTS  --disable-diskless"
fi  &&

if  [  "$GRUB_HERCULES"  =  "y"  ];  then
  OPTS="$OPTS  --enable-hercules"
else
  OPTS="$OPTS  --disable-hercules"
fi  &&

if  [  "$GRUB_SERIAL"  =  "y"  ];  then
  OPTS="$OPTS  --enable-serial"
else
  OPTS="$OPTS  --disable-serial"
fi  &&

if  [  "$GRUB_LINUX_MEM"  =  "y"  ];  then
  OPTS="$OPTS  --enable-auto-linux-mem-opt"
else
  OPTS="$OPTS  --disable-auto-linux-mem-opt"
fi  &&

# End setting up OPTS

# Launch automake tools to get the patchs options integrated
aclocal &&
automake &&
autoconf &&

./configure  --build=$BUILD             \
             --prefix=/usr              \
             --sbindir=/sbin            \
             --mandir=/usr/share/man    \
             --infodir=/usr/share/info  \
           $OPTS                        &&
invoke_gcc                              &&
make
