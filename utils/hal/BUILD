LDFLAGS="-lz $LDFLAGS"            &&
if [ "$SELINUX" == "y" ]; then
   OPTS="$OPTS --enable-selinux"
fi                                              &&
OPTS="$OPTS --with-pid-file=/var/run/hald.pid \
            --with-backend=linux \
            $HALACPI $HALAPM $HALSONY $HALPMU"  &&    
default_build            
