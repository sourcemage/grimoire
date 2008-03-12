export LDFLAGS="$LDFLAGS -L /usr/X11R6/lib"    &&

if [ "$CVS" = "yes" ]; then
  ./autogen.sh
fi                                          &&

./configure  --build=$BUILD                 \
             --prefix=${INSTALL_ROOT}/usr   \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
       --enable-python-runtime              \
       --enable-cxx-demos                   \
                       $OPTS                &&

###first time make will choke on bad "False"
make 
for i in $(grep -rl False Fresco-C++/);
do sedit "s/False/false/g" $i
done                                        &&
make_single                                 &&
make                                        &&
make_normal
