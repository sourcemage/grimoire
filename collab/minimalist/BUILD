# $Id: BUILD,v 1.2 2002/06/03 03:42:23 sergeyli Exp $
{
# First, add the global entry in aliases
echo " " > /etc/aliases.minimalist-sample &&
echo "# minimalist global entry:" >> /etc/aliases.minimalist-sample &&
echo "minimalist:	\"|/usr/sbin/minimalist.pl -d /etc/minimalist\"" >> /etc/aliases.minimalist-sample &&
echo "#" >> /etc/aliases.minimalist-sample &&
echo "# sample mailing list:" >> /etc/aliases.minimalist-sample &&
echo "list-sample:	\"|/usr/sbin/minimalist.pl -d /etc/minimalist list-sample\"" >> /etc/aliases.minimalist-sample &&
echo "list-sample-owner:	owner@myhost.mydomain.myzone" >> /etc/aliases.minimalist-sample &&

# Create config files directory
mkdir -p /etc/minimalist						&&

# Copy sample files
cp ./sample/lists.lst /etc/minimalist/lists.lst-sample			&&
cp -r ./sample/sample /etc/minimalist/					&&
cp ./minimalist.conf-sample /etc/minimalist/				&&

# Copy the progam file...
cp -v ./minimalist.pl /usr/sbin						&&

# Make spool dir
mkdir -p /var/spool/minimalist						&&
mkdir -p /var/spool/minimalist/list-sample				&&
echo "user@domain.zone" > /var/spool/minimalist/list-sample/list	&&
chown nobody.nogroup /var/spool/minimalist/list-sample			&&
chown nobody.nogroup /var/spool/minimalist/list-sample/list		&&

# Copy the help files
mkdir -p /usr/doc/minimalist						&&
cp -r ./docs /usr/doc/minimalist

} > $C_FIFO 2>&1


