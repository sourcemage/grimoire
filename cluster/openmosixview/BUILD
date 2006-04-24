(
for i in $(grep -rl CFLAGS= .);
do sedit "s/CFLAGS\=-O2 -O0/& $CFLAGS /g" $i
done
    prepare_install                          	&&
ln -sfn /lib/modules/$(uname -r)/build/include/hpc /usr/include &&
export QTDIR=/usr                               &&
    ./setup					&&
    cd 3dmon					&&
    ./setup.standalone                          &&  
if [ -e /etc/init.d/mosstatd.sh ]
then rm -f /etc/init.d/mosstatd.sh
fi                                              &&
if [ -e /etc/init.d/openmosixcollector ]
then rm -f /etc/init.d/openmosixcollector
fi                                              &&

echo "now type openmosixview <ENTER> and have fun!"
echo "(do not forget to copy the openmosixprocs binary to /usr/bin of each"
echo "your cluster-nodes e.g"
echo " rcp /usr/bin/openmosixprocs hostname_of_node:/usr/bin"
echo "or if you use SSH"
echo " scp /usr/bin/openmosixprocs hostname_of_node:/usr/bin"
echo "reply problems during installation to mosixview@t-online.de"
echo "Thanks"

#   /bin/cp -v openmosixcollector/openmosixcollector.init       \
#                            /etc/init.d/openmosixcollector.sh  &&
#   for  RUNLEVEL  in  3  4  5
#   do
#     ln  -svf  /etc/init.d/openmosixcollector.sh               \
#       /etc/rc${RUNLEVEL}.d/S55openmosixcollector
#   done
#
#  for  RUNLEVEL  in  0  1  2  6
#   do
#     ln  -svf  /etc/init.d/openmosixcollector.sh               \
#       /etc/rc${RUNLEVEL}.d/K45openmosixcollector
#   done

) > $C_FIFO 2>&1
