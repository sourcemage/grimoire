# don't assume a specific automake version
sedit  's/-${am__api_version}//'  configure 		&&
OPTS="$OPTS --enable-static=no" 			&&
./configure --prefix=${TRACK_ROOT}/usr  \
          --sysconfdir=${TRACK_ROOT}/etc  \
       --localstatedir=${TRACK_ROOT}/var  \
              --mandir=${TRACK_ROOT}/usr/share/man   \
             --infodir=${TRACK_ROOT}/usr/share/info  \
                       $OPTS                 		&&
/usr/lib/unsermake/unsermake
