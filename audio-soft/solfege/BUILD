./configure  --build=${BUILD}                    \
            --prefix=${INSTALL_ROOT}/usr/        \
            --libdir=${INSTALL_ROOT}/usr/lib     \
            --bindir=${INSTALL_ROOT}/usr/games   \
           --datadir=${INSTALL_ROOT}/usr/share/  \
        --sysconfdir=${INSTALL_ROOT}/etc         \
     --localstatedir=${INSTALL_ROOT}/var/games   \
                     ${OPTS}                     &&
if [ is_depends_enabled $SPELL gnome-doc-utils ] 
then
  make
else
  make skipmanual=yes
fi
