# XXX needed with GCC 10.x+
sedit '/^#define CcCmd\t/{s/$/ -fcommon/}' Xvnc/config/cf/linux.cf &&
check_tmp_noexec /tmp &&
xmkmf        &&
make_single  &&
make  World  &&
cd    Xvnc   &&
./configure  &&
check_tmp_noexec /tmp &&
make &&
make_normal
