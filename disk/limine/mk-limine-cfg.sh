#!/bin/bash
# create the limine config files
# run this script in the ESP partition, or a FAT32 boot partition

# Limine expects the boot kernels to exist on a FAT32 disk.

# Move any existing /boot files to the ESP (EFI System Partition).

# Whenever you update the kernel, mount the ESP over an empty /boot on your root file system.


cd /boot
#ROOT=`dracut --print-cmdline|cut -d\  -f1,2`
ROOT='root=LABEL=root'

if [[ -d /sys/firmware/efi ]];then
  echo This is a UEFI system
  SFX='.efi'
else
  echo This is a legacy BIOS system
fi



# build a microcode image
if `ls /sys/devices/platform/ |grep AMD > /dev/null`;then
  UCODE=amd
else
  UCODE=intel
fi
cat /lib/firmware/$UCODE-ucode/* > $UCODE-uc.img

DEST=limine.conf

cat > $DEST << EOF
limine:config:


verbose:yes
timeout:no
cmdline: $ROOT
interface_branding:SourceMage GNU/Linux (Limine boot)
interface_branding_colour: 6
wallpaper:boot():/limine/smgl-splash.png
wallpaper_style: centered
term_font_scale: 2x2

EOF

for VX in `ls vmlinuz-* | cut -d- -f2|sort -r`;do
  cat >> $DEST << EOF
/Linux $VX
protocol:linux
path:boot():/vmlinuz-${VX}${SFX}
module_path:boot():/$UCODE-uc.img

EOF

  MOD="initramfs-$VX.img"
  if [[ -f $MOD ]];then
    cat >> $DEST << EOF
       module_path:boot():/$MOD
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

# check for Windows
if WIN=`blkid | grep SYSTEM_DRV`; then
  WB=${WIN%:*}
  echo Windows installation found at $WB
  cat >> $DEST << EOF
/Windows
  image_path: hdd(1:1):/bootmgfw${SFX}
EOF

  if [[ -n $SFX ]];then
    echo  protocol: efi >> $DEST
  else
     echo  protocol: bios >> $DEST 
  fi
else
   echo Windows installation NOT found
fi

cat << EOF

Check the generated $DEST carefully, especially for Windows
/boot should be a FAT32 partition
Copy /usr/share/limine/* to /boot/limine/
On UEFI systems, the kernel needs efi support
EOF

if [[ -n $SFX ]];then
  cat << EOF
Finally, to create an entry in the UEFI Firmware,
   use the following command,
   changing /dev/...  as appropriate:

efibootmgr --create\
####           --disk /dev/sda1  ...\   ####
####           --disk /dev/nvme0n1 ...\ ####
####           --part 1\
           --label "SMGL Linux with Limine"\
           --loader '/limine/BOOTX64.EFI' 

EOF
fi

## add a reboot option ??
