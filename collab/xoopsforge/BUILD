# $Id: BUILD,v 1.1 2002/07/29 23:53:53 sergeyli Exp $
(

	[ `pwd` == $SOURCE_DIRECTORY ]                 &&
	rm -fr `find ./ -type d -and -name CVS`        &&
	rm -fr `find ./ -type f -and -name .cvsignore` &&

	prepare_install                                &&

	XOOPS=/usr/share/xoops/html                    &&
	cp    -r .    $XOOPS                           &&
	chmod -R 0755 $XOOPS/modules/xfmod/cache/
    
) > $C_FIFO 2>&1 && (

#	ALIAS=`grep '/usr/share/xoops/html/' /etc/httpd/httpd.conf | cut -d ' ' -f 2`

	echo "Please point your browser at <alias for /usr/share/xoops/html>/xf/install.php"
	echo "You will need to delete install.php afterwards."

)
