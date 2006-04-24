if [ -f /etc/profile.d/java.sh ]; then
  . /etc/profile.d/java.sh
fi                                      &&
. $SECTION_DIRECTORY/java-functions   &&
  
set_java_env  &&

cd $SOURCE_DIRECTORY  &&

./configure   --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS                 &&

make           &&
make install
