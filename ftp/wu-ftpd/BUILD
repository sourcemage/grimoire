 patch -p0 < $SPELL_DIRECTORY/config.sub.patch &&
 patch  -p1  <  $SCRIPT_DIRECTORY/wu-ftpd-2.6.1-fixinternalls.patch &&
 patch  -p1  <  $SCRIPT_DIRECTORY/wu-ftpd-2.6.1-privatepw.patch     &&
 patch  -p1  <  $SCRIPT_DIRECTORY/wu-ftpd-2.6.0-nonrootfix.patch    &&
 patch  -p0  <  $SOURCE_CACHE/$SOURCE2    &&
 patch  -p0  <  $SOURCE_CACHE/$SOURCE3    &&
 perl -i -p -e 's/\t=\t/\t/g' src/ftpcmd.y &&	
 ./configure --disable-quota --enable-pam --disable-rfc931 --enable-ratios \
	--enable-passwd --enable-ls $OPTS	&&
  make 
