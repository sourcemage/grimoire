#!/bin/bash
# create the limine config files
# run this script in the ESP partition, or a FAT32 boot partition

# Limine expects the boot kernels to exist on a FAT32 disk.

# Move any existing /boot files to the ESP (EFI System Partition).

# Whenever you update the kernel, mount the ESP over an empty /boot on your root file system.


cd /boot
ROOT=`dracut --print-cmdline|cut -d\  -f1,2`
#ROOT='root=LABEL=root64'

DEST=limine.conf

cat > $DEST << EOF
limine:config:


verbose:yes
cmdline: $ROOT
interface_branding:SourceMage GNU/Linux (Limine boot)
wallpaper:boot():/limine/smgl-splash.png

EOF

for VX in `ls vmlinuz-* | cut -d- -f2|sort -r`;do
  cat >> $DEST << EOF
/Linux $VX
protocol:linux
path:boot():/vmlinuz-$VX
EOF

  MOD='initramfs-$VX.img'
  if [[ -f $MOD ]];then
    cat >> $DEST << EOF
       module_path:boot():$MOD
EOF
  fi
done  # linux kernels

# extra systems
if  [[ -f memtest+ ]];then
      cat >> $DEST << EOF
/Memtest+
protocol:linux
path:boot():/memtest+

EOF
fi

if [[ -d sys/firmware/efi ]];then
  echo This is a UEFI system

# check for Windows
  if WIN=`blkid | grep SYSTEM_DRV`; then
    WB=${WIN%:*}
    echo Windows installation found at $WB
    cat >> $DEST << EOF
/Windows
    protocol: efi_chainload
    image_path: hd(0,1):/bootmgfw.efi
EOF
  fi


cat << EOF
Finally, to create an entry in the UEFI Firmware,
   use the following command,
   changing /dev/...  as appropriate:

efibootmgr --create\
           --disk /dev/sda...\
           --disk /dev/nvme...\
           --part 1\
           --label "SMGL Linux with Limine"\
           --loader '/limine/BOOTX64.EFI' 

EOF
else  # non UEFI
  echo this is not a UEFI system
# check for Windows
  if WIN=`blkid | grep SYSTEM_DRV`; then
    WB=${WIN%:*}
    echo Windows installation found at $WB
  cat >> $DEST << EOF
/Windows
    protocol: bios_chainload
    image_path: hd(0,1):/bootmgfw
EOF
  fi
fi

cat << EOF
Check the generated $DEST carefully, especially for Windows
EOF
