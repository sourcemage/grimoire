#!/bin/bash
# create the limine config files
# run this script in the ESP partition, or a FAT32 boot partition

# Limine expects the boot kernels to exist on a FAT32 disk.

# Move any existing /boot files to the ESP (EFI System Partition).

# Whenever you update the kernel, mount the ESP over an empty /boot on your root file system.

ROOT=`dracut --print-cmdline`
#ROOT='root=LABEL=root64'

DEST=limine.conf

cat > $DEST << EOF
limine:config:


verbose:yes
cmdline: $ROOT
interface_branding:SourceMage GNU/Linux (Limine boot)
wallpaper:boot():/smgl-splash.png

/SourceMage GNU/Linux
EOF

for VX in `ls /boot/vmlinuz-* | cut -d- -f2|sort -r`;do
  cat >> $DEST << EOF
//Linux $VX
protocol:linux
path:boot():/boot/vmlinuz-$VX
EOF

  MOD='/boot/initramfs-$VX.img'
  if [[ -f $MOD ]];then
    cat >> $DEST << EOF
       module_path:boot():$MOD
EOF
  fi
done  # linux kernels

# extra systems
if  [[ -f /boot/memtest+ ]];then
      cat >> $DEST << EOF
/Memtest+
protocol:linux
path:boot():/boot/memtest+

EOF
fi

