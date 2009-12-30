LDFLAGS="-lz $LDFLAGS"            &&
if [ "$SELINUX" == "y" ]; then
   OPTS="$OPTS --enable-selinux"
fi                                              &&
OPTS="$OPTS --with-pid-file=/var/run/hald.pid \
            --with-backend=linux \
            --disable-policy-kit \
            $HALACPI $HALAPM $HALSONY $HALPMU"  &&    
default_build            
