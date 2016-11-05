OPTS="$OPTS --build=${BUILD}"                           &&
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"
./configure --prefix="${INSTALL_ROOT}/usr"              \
        --sysconfdir="${INSTALL_ROOT}/etc"              \
     --localstatedir="${INSTALL_ROOT}/var"              \
            --mandir="${INSTALL_ROOT}/usr/share/man"    \
           --infodir="${INSTALL_ROOT}/usr/share/info"   \
     --with-auto-dir="${INSTALL_ROOT}/var/lib/auctex"   \
            --disable-build-dir-test                    \
                     $OPTS                              \
make                                                    &&
make tex-site.el                                        &&
cp tex.el style/tex.el                                  &&
cp tex-site.el style/tex-site.el                        &&
emacs -Q -batch -l lpath.el -f batch-byte-compile       \
      tex-jp.el prv-emacs.el preview.el
