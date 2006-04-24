(
	
 patch  -p1  <  $SCRIPT_DIRECTORY/wu-ftpd-2.6.1-fixinternalls.patch &&
 patch  -p1  <  $SCRIPT_DIRECTORY/wu-ftpd-2.6.1-privatepw.patch     &&
 patch  -p1  <  $SCRIPT_DIRECTORY/wu-ftpd-2.6.0-nonrootfix.patch    &&
 patch  -p0  <  $SOURCE_CACHE/$SOURCE2    &&
 patch  -p0  <  $SOURCE_CACHE/$SOURCE3    &&
 perl -i -p -e 's/\t=\t/\t/g' src/ftpcmd.y &&	
 ./configure --disable-quota --enable-pam --disable-rfc931 --enable-ratios \
	--enable-passwd --enable-ls $OPTS	&&
  make                                          &&
  prepare_install            			&&
  make    prefix=${INSTALL_ROOT}/usr	install

) > $C_FIFO 2>&1  &&  (

 cat > /etc/pam.d/ftp <<EOF
#
# The PAM configuration file for the `ftp' service
#
auth		requisite	pam_listfile.so item=user sense=deny file=/etc/ftplockout onerr=succeed
auth		sufficient	pam_ftp.so
auth		requisite	pam_shells.so
auth		required	pam_unix.so
account		required	pam_unix.so
session		required	pam_unix.so
session		required	pam_limits.so
EOF

 cat > /etc/xinetd.d/wu-ftpd <<EOF
service ftp
{
	socket_type	= stream
	protocol	= tcp
	wait		= no
	user		= root
	server		= /usr/sbin/in.ftpd
	server_args	= -l -a
	per_source	= 8
	log_type	= FILE /var/log/xinetd/wu-ftpd
	log_on_success	= PID HOST USERID EXIT DURATION
	log_on_failure	= USERID ATTEMPT
}
EOF

 mkdir 		-p		/home/ftp
 chown		root.ftp	/home/ftp
 chmod 		755		/home/ftp
 chmod 		644 		/etc/xinetd.d/wu-ftpd
 chmod 		644 		/etc/pam.d/ftp

) 
