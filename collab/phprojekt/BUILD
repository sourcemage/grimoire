# $Id: BUILD,v 1.1 2002/10/10 05:17:55 sergeyli Exp $
(
	prepare_install                                    &&

	mkdir -p   /usr/share/$SPELL                       &&
	cp    -R . /usr/share/$SPELL/
    
) > $C_FIFO 2>&1 && (

	echo "Please point your apache at /usr/share/$SPELL/html"
	echo "Edit or update /usr/share/$SPELL/php/config.pinc"
	echo "as well as /usr/share/$SPELL/apache.conf"
	echo "Access document scheme.php to create/update database schema"
	echo "and then remove scheme.php and update.php from the file system"

)
