(

# apache/apache2 auto setup
if  spell_ok  "apache";  then
# location to httpd root doc dir
  LOC="/usr/share/httpd"									&&
# same, but to be used withing search/replace regexp
  SLOC="\/usr\/share\/httpd"
elif  spell_ok  "apache-mod_ssl";  then
  LOC="/usr/share/httpsd"									&&
  SLOC="\/usr\/share\/httpsd\/htdocs"
  SLOC="\/usr\/share\/httpsd"
elif  spell_ok  "apache2";  then
  LOC="/usr/share/apache2"									&&
  SLOC="\/usr\/share\/apache2"
fi												&&

if [ "$LOC" == "" ]; then
  message "${MESSAGE_COLOR}Unable to find apache or apache2 installed version..."		&&
  message "$SPELL cast aborded. ${DEFAULT_COLOR}"						&&
  return 1
fi												&&

prepare_install											&&
			
# move docs
mkdir -p /usr/doc/openwebmail 1>/dev/null 2>&1							&&
cp -r ./data/openwebmail/doc/* /usr/doc/openwebmail 1>/dev/null 2>&1 				&&
rm -r -f ./data/openwebmail/doc									&&

# check for previous config file
if [ -e /etc/openwebmail.conf ]; then
 message " "											&&
 message "${MESSAGE_COLOR}Previous config file detected..."					&&
 message "The new sample config file will be named openwebmail-new.conf." 			&&
 message "Your actual config is maintained (beware of conf file format changes)."		&&
 message " ${DEFAULT_COLOR}" 									&&

 mv ./cgi-bin/openwebmail/etc/openwebmail.conf /etc/openwebmail-new.conf  1>/dev/null 2>&1 
else
 mv ./cgi-bin/openwebmail/etc/openwebmail.conf /etc/openwebmail.conf 1>/dev/null 2>&1
fi												&&

# move http and bin
cp -ra ./cgi-bin/* $LOC/cgi-bin/ 1>/dev/null 2>&1						&&
cp -ra ./data/* $LOC/htdocs/ 1>/dev/null 2>&1							&&

ln -sfn /etc/openwebmail.conf $LOC/cgi-bin/openwebmail/etc/openwebmail.conf 1>/dev/null 2>&1	&&

# Security team'll shoot me...
message "${MESSAGE_COLOR}Setting up rights... ${DEFAULT_COLOR}"					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail.pl 	 					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-main.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-abook.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-advsearch.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-cal.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-folder.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-vdomain.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-webdisk.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-prefs.pl  					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-read.pl						&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-viewatt.pl					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-send.pl						&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-spell.pl					&&
chmod 4555 $LOC/cgi-bin/openwebmail/openwebmail-tool.pl						&&
chmod 775       $LOC/cgi-bin/openwebmail/etc/sessions  						&&
chown root.mail $LOC/cgi-bin/openwebmail/etc/sessions  						&&

message "${MESSAGE_COLOR}Setting up log... ${DEFAULT_COLOR}" 					&&
[ -x /var/log/openwebmail.log ] || touch /var/log/openwebmail.log 1>/dev/null 2>&1		&&
chown nobody.nogroup /var/log/openwebmail.log							&&
chmod 660            /var/log/openwebmail.log							&&

# At this time, I have no clue about PAM support for Perl... fallback to unix auth
#echo "auth       required     /lib/security/pam_unix.so" > /etc/pam.d/openwebmail		&&
#echo "account    required     /lib/security/pam_unix.so">> /etc/pam.d/openwebmail		&&
#echo "password   required     /lib/security/pam_unix.so">> /etc/pam.d/openwebmail		&&

# This is for future use of perl+PAM
#echo "auth       required     /lib/security/pam_unix.so" > /etc/pam.d/openwebmail		&&
#echo "account    required     /lib/security/pam_unix.so">> /etc/pam.d/openwebmail		&&
#echo "password   required     /lib/security/pam_unix.so">> /etc/pam.d/openwebmail		&&

#
# apply a patch to avoid DB error
#
#patch $LOC/cgi-bin/openwebmail/openwebmail-tool.pl < $SCRIPT_DIRECTORY/openwebmail-tool.pl-DB.patch &&

# Tune OWM defaults to SMGL style
message "${MESSAGE_COLOR}Tuning OpenWebMail defaults to SMGL style... ${DEFAULTS_COLOR}"	&&
message "${MESSAGE_COLOR}Directories... ${DEFAULTS_COLOR}"        				&&
sedit "s/\/var\/mail/\/var\/spool\/mail/" $LOC/cgi-bin/openwebmail/etc/openwebmail.conf 	&&
sedit "s/\/usr\/local\/www\/data\/openwebmail/$SLOC\/htdocs\/openwebmail/"  $LOC/cgi-bin/openwebmail/etc/openwebmail.conf &&
sedit "s/\/usr\/local\/www\/cgi-bin\/openwebmail/$SLOC\/cgi-bin\/openwebmail/" $LOC/cgi-bin/openwebmail/etc/openwebmail.conf &&
message "${MESSAGE_COLOR}Perl db extentions... ${DEFAULTS_COLOR}"        			&&
sedit "s/^dbm_ext.*$/dbm_ext .db/" $LOC/cgi-bin/openwebmail/etc/openwebmail.conf		&&
sedit "s/^dbmopen_ext.*$/dbmopen_ext %dbm_ext%/" $LOC/cgi-bin/openwebmail/etc/openwebmail.conf	&&
sedit "s/^dbmopen_haslock.*$/dbmopen_haslock yes/" $LOC/cgi-bin/openwebmail/etc/openwebmail.conf &&
sedit "s/^spellcheck.*$/spellcheck \/usr\/bin\/ispell/" $LOC/cgi-bin/openwebmail/etc/openwebmail.conf		
message "${MESSAGE_COLOR}Passwd files in OWM auth_unix.pl file... ${DEFAULT_COLOR}"             &&
sedit "s/\/etc\/master.passwd/\/etc\/shadow/"  $LOC/cgi-bin/openwebmail/etc/defaults/auth_unix.conf
sedit "s/\/usr\/sbin\/pwd_mkdb/none/"  $LOC/cgi-bin/openwebmail/etc/defaults/auth_unix.conf

# Initialize openwebmail
if [ "$MAIL_STATS" == "n" ]; then
  MAIL_OPT="--no"
else
  MAIL_OPT="--yes"
fi                                                                                              &&
# Overwrite dbm.conf file 
cp -f $SCRIPT_DIRECTORY/dbm.conf $LOC/cgi-bin/openwebmail/etc/defaults/ 1>/dev/null 2>&1 &&

message "${MESSAGE_COLOR}Initializing OpenWebmail... ${DEFAULT_COLOR}"                          &&
$LOC/cgi-bin/openwebmail/openwebmail-tool.pl --init $MAIL_OPT                                   &&

mv "$LOC/htdocs/openwebmail/help/fr/templates_and_data/version notes.txt" \
    $LOC/htdocs/openwebmail/help/fr/templates_and_data/version_notes.txt                        &&

# link index.html to the redirect page
ln -sf redirect.html $LOC/htdocs/openwebmail/index.html

) > $C_FIFO 2>&1
