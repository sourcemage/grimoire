# change defaults
sedit 's|web2ldaprun|nobody|' etc/web2ldap/web2ldapcnf/standalone.py &&
sedit 's|/tmp/fcgi/web2ldap-fastcgi.pid|/var/run/web2ldap-fastcgi.pid|' etc/web2ldap/web2ldapcnf/fastcgi.py &&

python sbin/compile.py &&

rm -fr var
