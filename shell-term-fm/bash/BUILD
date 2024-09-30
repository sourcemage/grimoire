[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

OPTS+=" $BASH_OPTS" &&

./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr  \
             --bindir=${TRACK_ROOT}/bin  \
             --sysconfdir=${TRACK_ROOT}/etc \
             --localstatedir=${TRACK_ROOT}/var \
             --mandir=${TRACK_ROOT}/usr/share/man \
             --infodir=${TRACK_ROOT}/usr/share/info \
             --enable-static-link          \
             --with-bash-malloc=no 	   \
             $OPTS                         &&
make  bash DESTDIR=$INSTALL_ROOT           &&
mv    bash  bash.static                    &&
make  clean                                &&

./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr  \
             --bindir=${TRACK_ROOT}/bin  \
             --sysconfdir=${TRACK_ROOT}/etc \
             --localstatedir=${TRACK_ROOT}/var \
             --mandir=${TRACK_ROOT}/usr/share/man \
             --infodir=${TRACK_ROOT}/usr/share/info \
             --with-bash_malloc=no         \
             $OPTS                         &&
make DESTDIR=$INSTALL_ROOT &&

mkdir -p "${SOURCE_DIRECTORY}/INSTALL_ROOT" &&

make_normal  &&
#
# If bash is installed on a system without /bin then /bin will be just a file
# instead of a directory
# Bash is the first package installed by baseystem that writes to /bin
#
install  -d  -m  755  -o  root  -g  root  ./INSTALL_ROOT/bin  &&

cp  -f   bash         ./INSTALL_ROOT/bin      &&
cp  -f   bashbug      ./INSTALL_ROOT/bin      &&
ln  -sf  bash         ./INSTALL_ROOT/bin/sh   &&

# install static bash
install  -D  -m  755  bash.static  "./INSTALL_ROOT/sbin/bash.static"  &&
# compatibility with older bash spell
ln  -fns  ../sbin/bash.static  "./INSTALL_ROOT/bin/bash.static"  &&

# create restricted shell
ln  -fns  bash  ./INSTALL_ROOT/bin/rbash
