  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure --build=$BUILD                                  \
            --prefix=${TRACK_ROOT}/usr                    \
            --infodir=${TRACK_ROOT}/usr/share/info        \
            --mandir=${TRACK_ROOT}/usr/share/man          \
	        $OPTS	                                        &&
make DESTDIR=$INSTALL_ROOT
