make_single  &&

if [ "$CVS" == "y" ]; then
   export OPENH323DIR=$SOURCE_DIRECTORY         &&
   cd $SOURCE_DIRECTORY                         &&
   ./configure --prefix=/usr                    \
               --sysconfdir=/etc                \
               --localstatedir=/var             \
               $OPTS                            &&
    make -j 1 optshared
else
   ./configure --prefix=/usr $OPTS 		&&
#   patch -p0 < $SCRIPT_DIRECTORY/patch_openh323 &&
   LD_PRELOAD_OLD="$LD_PRELOAD"                 &&
   unset LD_PRELOAD                             &&
   make	-j 1					&&
   export LD_PRELOAD="$LD_PRELOAD_OLD"          
fi  &&

make_normal
