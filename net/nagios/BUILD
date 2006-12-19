if [ "$NAGIOS_HTML" == "y" ]; then
   local HTML_DIR="${INSTALL_ROOT}/usr/share/nagios/htdoc"   &&
   local CGI_DIR="${INSTALL_ROOT}/usr/share/nagios/cgi-bin"
   local NAGIOS_HTMLCGI_OPTS="--datadir=${HTML_DIR} --sbindir=${CGI_DIR}" &&
fi                                                           &&

create_account nagios                                        &&
create_account nagcmd                                        &&

./configure  --prefix=${INSTALL_ROOT}/usr                                \
             --sysconfdir=${INSTALL_ROOT}/etc/nagios                     \
             --localstatedir=${INSTALL_ROOT}/var/lib/nagios              \
             --mandir=${INSTALL_ROOT}/usr/share/man                      \
             --infodir=${INSTALL_ROOT}/usr/share/info                    \
             ${NAGIOS_HTMLCGI_OPTS}                                      \
             --with-command-user=nagcmd                                  \
             --with-command-group=nagcmd                                 \
             --with-lockfile=${INSTALL_ROOT}/var/lock/nagios/nagios.pid  \
             --enable-nanosleep                                          \
             ${OPTS}                                                     &&

make all                                               
